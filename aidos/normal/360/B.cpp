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
int n, k;
ll a[2020];
int dp[2020];
int calc(ll v) {
	for(int i = 0; i < n; i++){
		dp[i] = i;
		for(int j = 0; j < i; j++) {
			if(abs(a[i] - a[j]) <= v * (i-j)) {
				dp[i] = min(dp[i], dp[j] + i - j - 1);
			}
		}
	}
	int ans = n;
	for(int i = 0; i < n; i++) ans = min(dp[i]+n-i-1, ans);
	return ans;
}
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll l = 0, r = 0;	
	for(int i=1; i < n; i++) r = max(r, abs(a[i] - a[i-1]));
	ll res = r;
	while(l <= r) {
		ll mid = (l + r)>>1;
		if(calc(mid) <= k) {
			res = mid;
			r = mid-1;
		}else l = mid+1;
	}
	cout << res << "\n";
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