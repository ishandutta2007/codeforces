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
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
ll dp[(1<<20)][20];
int a[21][21];
ll get(int mask, int c, int fi){
	ll &res = dp[mask][c];
	if(res != -1) return res;
	res = 0;
	for(int i = fi; i < n; i++){
		if(a[c][i]) {
			if(i==fi){
				if(mask^(1<<c) ^(1<<i)) {
					res++;
				}
			}else if((mask&(1<<i)) == 0){
				res += get(mask | (1<<i), i, fi);
			}
		}
	}
	return res;
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		a[x-1][y-1] = 1;
		a[y-1][x-1] = 1;
	}
	memset(dp, -1, sizeof dp);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += get(1<<i, i, i);
	}
	cout << ans/2 <<"\n";
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