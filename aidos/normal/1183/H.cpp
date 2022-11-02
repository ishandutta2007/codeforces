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
int n;
string s;
ll k;
vector<int> last[26];
ll dp[111][111];
void solve(){
	cin >> n >> k >> s;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		int cur = s[i-1] - 'a';
		for(int j = 0; j < i; j++) {
			for(int kk = 0; kk < n; kk++) {
				dp[i][kk+1] += dp[j][kk];
			}
		}
		for(int t = 0; t < last[cur].size(); t++){
			for(int kk = 1; kk <= n; kk++) {
				dp[i][kk] -= dp[last[cur][t]][kk];
			}
		}
		
		last[cur].pb(i);
	}
	/*
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n;j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	ll ans = 0;
	for(int kk = n; kk >= 0; kk--) {
		for(int j = 0; j <= n && k > 0; j++) {
			ll d = min(k, dp[j][kk]);
			k -= d;
			ans += d * (n-kk);
		}
	}
	if(k == 0) {
		cout << ans << "\n";
	}
	else cout << -1 << "\n";
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