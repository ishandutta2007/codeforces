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
ll dp[500300];
int was[500500];
int cnt[500500];
ll calc(ll n, ll m, ll a, ll b){
	ll g = __gcd(a, b);
	ll ans = 0;
	ll cnt2 = 0;
	for(ll i = 0; i < g; i++){
		if(n < i) continue;
		ll c = (n-i)/g + 1;
		ll d = (m-i)/g + 1;
		cnt2 += d - c;
		ans -= i * (d-c);
	}
	ans += m * (m + 1)/2 - n * (n + 1)/2;
	ans /=g;
	ans += cnt2;
	return ans;
}
void solve(){
	ll m, a, b;
	cin >> m >> a >> b;
	ll ans = 0;
	ll n = 500000;
	if(n>m) n = m;
	for(int i = 0; i <= n; i++){
		dp[i] = n + 1;
	}
	dp[0] = 0;
	set<pll> S;
	S.insert(mp(0, 0));
	while(S.size() > 0){
		int v = S.begin()->s;
		ll d = S.begin()->f;
		S.erase(S.begin());
		if(was[v]) continue;
		was[v] = 1;
		ll g = v + a;
		if(g <= n && dp[g] > max(g, d)) {
			dp[g] = max(g, d);
			S.insert(mp(dp[g], g));
		}
		g = v - b;
		
		if(g >= 0 && dp[g] > max(g, d)) {
			dp[g] = max(g, d);
			S.insert(mp(dp[g], g));
		}
	}
	for(int i = 0; i <= n; i++) cnt[dp[i]]++;
	for(int i = 1; i <= n; i++) cnt[i] += cnt[i-1];
	for(int i = 0; i <= n; i++) ans += cnt[i];
	ans += calc(n, m, a, b);
	cout << ans << "\n";
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