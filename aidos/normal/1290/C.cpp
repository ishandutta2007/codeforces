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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
char c[maxn];
vector<int> g[maxn];
int sz = 1;
ll S[maxn];
int p[maxn];
int pos[maxn];
int neg[maxn];
int ans = 0;
map< pair<int, int>, int > cur;
int C[maxn];
int T[maxn];

void erase(int x, int u) {
	if(cur.find(mp(x, u)) != cur.end()) {
		ans -= cur[mp(x, u)];
		cur.erase(mp(x, u));
	}
}
void add(int x, int u) {
	ans += min(S[x], S[u]);
	cur[mp(x, u)] = min(S[x], S[u]);
	//cout <<ans<<"asd\n";
}

int get(int v) {
	if(p[v] == v) return v;
	return p[v] = get(p[v]); 
}

void create(int x) {
	if(pos[x] == 0) {
		pos[x] = sz;
		S[sz] = 1;
		p[sz]=sz;
		T[sz] = 1;
		sz++;
		neg[x] = sz;
		p[sz] = sz;
		T[sz] = 1;
		sz++;
		add(pos[x], neg[x]);
	}
}
void MERGE(int u, int v) {
	int pu = get(u);
	int pv = get(v);
	if(pu == pv) return;
	p[pu] = pv;
	S[pv] += S[pu];
	T[pv] += T[pu];
}

void mergeOp(int u, int v) {
	create(u);
	create(v);

	int pos_u = get(pos[u]);
	int pos_v = get(pos[v]);
	int neg_u = get(neg[u]);
	int neg_v = get(neg[v]);
	
	erase(pos_u, neg_u);
	erase(pos_v, neg_v);
	erase(neg_u, pos_u);
	erase(neg_v, pos_v);

	MERGE(pos_u, pos_v);
	MERGE(neg_u, neg_v);
	int posv = get(pos[v]);
	int negv = get(neg[v]);
	if(posv == negv) {

	}else{
		add(posv, negv);
	}
}
void merge(int u, int v) {
	create(u);
	create(v);
	int pos_u = get(pos[u]);
	int pos_v = get(pos[v]);
	int neg_u = get(neg[u]);
	int neg_v = get(neg[v]);

	erase(pos_u, neg_u);
	erase(pos_v, neg_v);
	erase(neg_u, pos_u);
	erase(neg_v, pos_v);
	
	MERGE(pos_u, neg_v);
	MERGE(neg_u, pos_v);

	int posv = get(pos[v]);
	int negv = get(neg[v]);
	if(posv == negv) {

	}else{
		add(posv, negv);
	}
}

void solve(){
	scanf("%d%d", &n, &k);
	scanf("%s", c);
	for(int i = 1;i <= k; i++){
		int s;
		scanf("%d", &s);
		for(int j = 0; j < s; j++) {
			int x;
			scanf("%d", &x);
			g[x].pb(i);
		}
	}
	int d = k+1;

	for(int i = 1; i <= n; i++) {
		if(c[i-1] == '1') {
			int t = g[i].size();
			if(t == 0) {
				//continue;
			}else if(t == 1) {
				create(d);
				erase(pos[d], neg[d]);
				erase(neg[d], pos[d]);				
				S[neg[d]] = 0; 
				S[pos[d]] = inf;
				mergeOp(d, g[i][0]);
				//merge(g[i][0], g[i][0]);
				d++;
//				continue;
			} else {
				//cout << g[i][0] << " "<<g[i][1] << " " << i << "g\n";
				mergeOp(g[i][0], g[i][1]);

			}
		} else {
			int t = g[i].size();
			if(t == 1) {
				create(d);
				erase(pos[d], neg[d]);
				erase(neg[d], pos[d]);				
				S[neg[d]] = inf; 
				S[pos[d]] = 0;
 				mergeOp(d, g[i][0]);
				d++;
			}else {
				//cout << g[i][0] << " "<<g[i][1] << " " << i << "g\n";
				merge(g[i][0], g[i][1]);
			}
		}
		cout << ans << "\n";
	}
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}