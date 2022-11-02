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
ll a, b;
void solve(){
	cin >> a >> b;
	ll g = __gcd(a, b);
	a/=g;
	b/=g;
	ll ans = b;
	vector<ll> P;
	ll z = b;
	for(ll i = 2; i*i <= z; i++) {
		if(z % i == 0) {
			P.push_back(i);
			while(z % i == 0) z/=i;
		}
	}
	if(z > 1) P.push_back(z);
	int m = P.size();
	for(int mask = 1; mask < (1<<m); mask++) {
		ll cur = 1;
		for(int i = 0; i < m; i++) {
			if(mask & (1<<i)) cur *= P[i];
		}
		ll d = (cur - a % cur) % cur;
		ll cnt = (b-d)/cur + 1;
		if(__builtin_popcount(mask) % 2) ans -= cnt;
		else ans += cnt;
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