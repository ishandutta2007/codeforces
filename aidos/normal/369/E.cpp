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

const int inf = (1ll << 25) - 1;
const int maxn = (int)1e6+20;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
vector<int> g[maxn];
vector< pii> q[maxn];
int ans[maxn];
int t[maxn];

void upd(int v) {
	while(v < maxn) {
		t[v]++;
		v |= (v+1);
	}
}
int get(int v) {
	int res = 0;
	while(v >= 0) {
		res += t[v];
		v = (v&(v+1)) - 1;
	}
	return res;
}
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		g[r].pb(l);
	}
	for(int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		int last = 1;
		for(int j = 0; j < k; j++) {
			int x;
			scanf("%d", &x);
			q[x].pb(mp(last, i));
			last = x + 1;		
		}
	}
	for(int i = maxn-1; i >= 1;i--) {
		for(auto &z: g[i]) {
			upd(z);
		}
		int x = get(i);
		for(auto &z: q[i]) {
			ans[z.s] += x - get(z.f - 1); 
		}
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
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