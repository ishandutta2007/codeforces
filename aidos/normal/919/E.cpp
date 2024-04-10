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

using namespace std;
int p, a, b;
int inv[1000100];
ll x;

int binpow(int d, int c, int mod){
	int res = 1 % mod;
	while(c > 0){
		if(c & 1) res = (res * 1ll * d) % mod;
		d = (d * 1ll * d) % mod;
		c>>=1;
	}
	return res;
}

ll calc(ll x){
	int res = 1;
	ll ans = 0;
	for(int i = 0; i < p-1; i++){
		int N = (inv[res] * 1ll * b) % p;
		ll t = (i - N + p-1) % (p-1);
		for(int j = 0; j < 4; j++){
			if(t * 1ll * p + N <= x) ans++;
			t = (t + p - 1);
		}
		res = (res * 1ll * a) % p;
	}
	return ans;
}
void solve(){
	cin >> a >> b >> p >> x;
	for(int i = 0; i < p; i++){
		inv[i] = binpow(i, p-2, p);
	}
	ll a1 = x % (p*1ll*(p-1));
	ll a2 = x / (p * 1ll * (p-1));
	cout <<(calc(a1) + a2 * calc(p*1ll*(p-1) - 1)) << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}