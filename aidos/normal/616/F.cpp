
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;

int nsuff[600200];
int suff[600200];
int ncolor[600200];
int color[600200];
int head[600200];
int p[600200];
int lcp[600200];

int s[600100];
int nxt[600100];
int id[600100];
bool cmp(int i, int j){
	return s[i] < s[j];
}
int sz = 0;
void suffix_array(){
	int n = sz;
	for(int i = 0; i < n; i++){
		suff[i] = i;
	}

	sort(suff, suff + n, cmp);
	int cn = 0;
	for(int i = 0; i  < n; i++){
		if( i == 0 || s[suff[i]]!= s[suff[i-1]]){
			head[cn] = i;
			color[suff[i]] = cn++;
		}
		else color[suff[i]] = cn-1;
	}

	for(int len = 1; len <= n; len <<= 1){
		for(int i = 0; i < n ;i++){
			int pos = suff[i] - len;
			if( pos < 0) pos += n;
			ncolor[i] = color[i];
			nsuff[head[color[pos]]++] = pos;
		}
		cn = 0;
		for(int i = 0; i < n; i++){
			suff[i] = nsuff[i];
			if(i == 0 || ncolor[suff[i]] != ncolor[suff[i-1]] || ncolor[(suff[i] + len) % n] != ncolor[(suff[i-1] + len) % n]){
				head[cn] = i;
				color[suff[i]] = cn++;
			}
			else color[suff[i]] = cn-1;
		}
	}
	
	for(int i = 0; i < n; i++){
		p[suff[i]] = i;
	}
	int m = 0;
	for(int i = 0; i < n; i++){
		int pos = p[i];
		if( pos == n-1){
			lcp[pos] = 0;
			m = 0;
			continue;
		}
		m = max(0, m - 1);
		while( i + m < n && suff[pos + 1] + m < n && s[i + m] == s[suff[pos + 1] + m]) m++;
		lcp[pos] = m;
	}
}

struct node {
	vector < node * > childrens;
	node * parent;
	int depth;
	ll ans;
	node(){
		parent = NULL;
		depth = 0;
		ans = 0;
	}

	node(node * _parent, int _depth){
		parent = _parent;
		depth = _depth;
		ans = 0;
	}
};

node * buildsuffixtree(node * &root, int len, int lcp, ll val){
	if( root-> depth == 0 || root->depth == lcp){
		if(root->depth == len){
			root->ans += val;
			return root;
		}
		node * added = new node (root, len);
		added->ans += val;
		root->childrens.pb(added);
		return added;
	}
	if(root->parent->depth < lcp){
		node * added = new node (root->parent, lcp);
		root->parent->childrens.pop_back();
		root->parent->childrens.pb(added);
		added->childrens.pb(root);
		root->parent = added;
	}
	return buildsuffixtree(root->parent, len, lcp, val);
}

int v[200200];

ll ans = 0;
char c[500500];
void traverse(node * &root){
	for(int i = 0; i < root->childrens.size(); i++){
		traverse(root->childrens[i]);
		root->ans += root->childrens[i]->ans;
	}
	ans = max(ans, root->ans * 1ll * root->depth);
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
    	scanf("%s", &c);
    	int m = strlen(c);
    	int el = sz + m;
    	for(int j = 0; j < m; j++){
    		nxt[sz] = el;
    		id[sz] = i;
    		s[sz++] = c[j] - 'a';
    	}
    	nxt[sz] = el;
    	id[sz] = i;
    	s[sz++] = -1 - i;
    }
    for(int i = 0; i < n; i++){
    	scanf("%d", &v[i]);
    }
    suffix_array();

    node * root = new node();
    node * cur = root;
    for(int i = 0; i < sz; i++) {
    	if(nxt[suff[i]] == suff[i]) continue;
    	cur = buildsuffixtree(cur, nxt[suff[i]] - suff[i], lcp[i-1], v[id[suff[i]]]);
    }
    traverse(root);
    cout << ans << endl;
    

    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}