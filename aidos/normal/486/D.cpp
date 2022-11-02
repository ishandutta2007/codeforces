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
#include <bitset>

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
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
vector<int> g[2020];
int a[2020];
pii p[2020];
int was[2020];
int u[2020];
int d;
int L;
int T;
ll calc(int v, int pa) {
	ll res=1;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(to == pa || was[to] || a[to] - L > d) {
			continue;
		}
		res = (res*(calc(to, v)+1)) % mod;
	}
	return res;
}
void solve(){
	cin>>d >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		p[i]=mp(a[i], i);
	}
	sort(p, p + n);
	for(int x = 1; x < n; x++){
		int u, v;
		cin >> u >> v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int v = p[i].s;
		L = p[i].f;
		T++;
		ans += calc(v, -1);
		was[v] = 1;
	}
	cout << ans % mod << "\n";
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