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


int m, q;
string cc[200100], s;

int a[500100];
int p[400100], cnt[400100], c[400100];
int pn[400100], cn[400100];
int n;


vector<int> t[4*400100];
 
void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = vector<int> (1, a[p[tl]]);
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		merge (t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
			back_inserter (t[v]));
	}
}
int query (int v, int tl, int tr, int l, int r, int x, int y) {
	if (l > r)
		return 0;
	if (l == tl && tr == r) {
		vector<int>::iterator pos = lower_bound (t[v].begin(), t[v].end(), x);
		vector<int>::iterator pos2 = upper_bound (t[v].begin(), t[v].end(), y);
		
		if (pos != t[v].end()){
			if(pos2 != t[v].end())
				return pos2 - pos;
			return t[v].end() - pos;
		}
		return 0;
	}
	int tm = (tl + tr) / 2;
	return query (v*2, tl, tm, l, min(r,tm), x, y)+query (v*2+1, tm+1, tr, max(l,tm+1), r, x, y);
}
	
void suffix_array(){
	for (int i=0; i<n; ++i)
		++cnt[s[i]];
	for (int i=1; i<10000; ++i)
		cnt[i] += cnt[i-1];
	for (int i=0; i<n; ++i)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i=1; i<n; ++i) {
		if (s[p[i]] != s[p[i-1]])  ++classes;
		c[p[i]] = classes-1;
	}
	for (int h=0; (1<<h)<n; ++h) {
		for (int i=0; i<n; ++i) {
			pn[i] = p[i] - (1<<h);
			if (pn[i] < 0)  pn[i] += n;
		}
		memset (cnt, 0, classes * sizeof(int));
		for (int i=0; i<n; ++i)
			++cnt[c[pn[i]]];
		for (int i=1; i<classes; ++i)
			cnt[i] += cnt[i-1];
		for (int i=n-1; i>=0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i=1; i<n; ++i) {
			int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
			if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
			++classes;
			cn[p[i]] = classes-1;
		}
		memcpy (c, cn, n * sizeof(int));
	}
//	for(int i = 0; i < n; i++){
//		cout << p[i] << " ";
//	}
//	cout << endl;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> m >> q;
    for(int i = 0; i < m; i++){
    	cin >> cc[i];
    	int pos = s.size();
    	s += cc[i];
    	s += '#';
    	while(pos < s.size()){
    		a[pos] = i;
    		pos++;
    	}
    }
    n = s.size();
    suffix_array();
	build(1, 0, n-1);
//	cout  << s << endl;
	for(int i = 0; i < m; i++){
		int len = cc[i].size();
		int l = 0, r = n-1;
		//cout << cc[i] << " ";
		//cout << len << endl;
		for(int j = 0; j < len; j++){
			int tl = l;
			int tr = r;
			int ans = l;
			while(tl <= tr){
				int mid = (tl+tr) >> 1;
				
				if(cc[i][j] < s[p[mid] + j]) {
					tr = mid-1;
				}
				else if(cc[i][j] > s[p[mid]+j]){
					tl = mid+1;
				}else {
					tr = mid-1;
					ans=mid;
				}
			}
			tl = ans;
			l = ans;
			tr = r;
			ans = r;
			while(tl <= tr){
				int mid = (tl+tr) >> 1;
				
				if(cc[i][j] < s[p[mid] + j]) {
					tr = mid-1;
				}
				else if(cc[i][j] > s[p[mid]+j]){
					tl = mid+1;
				}else {
					tl = mid+1;
					ans=mid;
				}
			}
			r = ans;
		}
		c[i] = l;
		cn[i] = r;
	}

	for(int i = 0, l, r, k; i < q; i++){
		scanf("%d %d %d\n", &l, &r, &k);
		l--;
		r--;
		k--;
		printf("%d\n", query(1, 0, n-1, c[k], cn[k], l, r));
	}








    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}