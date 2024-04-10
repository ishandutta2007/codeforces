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

const int inf = (1 << 29) - 1;
const int maxn = (int)3e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m, k, q;
vector<int> g[maxn];
int u[maxn];
int prv[maxn];
int nxt[maxn];
ll dp[maxn][2];
void solve(){
	cin >> n >> m >> k >> q;
	for(int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		g[r].pb(c);
	}
	for(int i = 0; i < q; i++) {
		int x;
		cin >> x;
		u[x] = 1;
	}
	for(int i = 1; i <= m; i++) {
		prv[i] = prv[i-1];
		if(u[i]) prv[i] = i;
	}
	for(int i = m; i > 0; i--) {
		nxt[i] = nxt[i+1];
		if(u[i]) nxt[i] = i;
	}
	while(g[n].size()==0) {
		n--;
	}
	g[1].pb(1);
	for(int i = 1; i <= n; i++) {
		sort(all(g[i]));
	}
	int d = g[1].back();
	dp[1][0] = 1ll<<50;
	dp[1][1] = d-1;
	int last = 1;
	for(int I = 2; I <= n; I++) {
		if(g[I].size()==0) continue;
		int pos = g[last][0];
		dp[I][0] = dp[I][1] = 1ll<<50;
		ll ad = I-last + g[I].back()-g[I][0];
		int curL = g[I][0];
		int curR = g[I].back();
		{
			int ni = prv[pos];
			if(ni) {
				dp[I][1] = min(dp[I][1], dp[last][0] + abs(ni-pos) + ad + abs(curL - ni));
				dp[I][0] = min(dp[I][0], dp[last][0] + abs(ni-pos) + ad + abs(curR - ni));
			}
			ni = nxt[pos];
			if(ni) {
				dp[I][1] = min(dp[I][1], dp[last][0] + abs(ni-pos) + ad + abs(curL - ni));
				dp[I][0] = min(dp[I][0], dp[last][0] + abs(ni-pos) + ad + abs(curR - ni));
			}
		}
		pos = g[last].back();
		{
			int ni = prv[pos];
			if(ni) {
				dp[I][1] = min(dp[I][1], dp[last][1] + abs(ni-pos) + ad + abs(curL - ni));
				dp[I][0] = min(dp[I][0], dp[last][1] + abs(ni-pos) + ad + abs(curR - ni));
			}
			ni = nxt[pos];
			if(ni) {
				dp[I][1] = min(dp[I][1], dp[last][1] + abs(ni-pos) + ad + abs(curL - ni));
				dp[I][0] = min(dp[I][0], dp[last][1] + abs(ni-pos) + ad + abs(curR - ni));
			}
		}
		last = I;
	}
	cout << min(dp[n][0], dp[n][1]) << "\n";
}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}