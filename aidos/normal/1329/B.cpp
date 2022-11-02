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
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
ll a[100];
const int M = 30;
ll d, m;
ll dp[100];

ll calc(int pos) {
	ll &res = dp[pos];
	if(res != -1) return res;
	res = 1;
	for(int i = pos + 1; i < M; i++) {
		res = (res + calc(i) * 1ll * a[i]) % m;
	}
	return res;
}
void solve() {
	cin >> d >> m;
	if(m == 1) {
		cout << 0 << "\n";
		return;
	}
	for(int i = 0; i < M; i++) {
		ll x = 1<<i;
		if(x > d) {
			a[i] = 0;
		} else {
			ll y = min(2 * x - 1, d) - (x-1);
			a[i] = y;
		}
	}
	memset(dp, -1,sizeof dp);
	ll ans = 0;
	for(int i = 0; i < M; i++) {
		ans = (ans + calc(i) * 1ll * a[i]) % m;
	}
	cout << ans << "\n";
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}