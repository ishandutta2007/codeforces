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
int n, a[100100], b[100100];
int m;
int mod = 1000 * 1000 * 1000 + 7;
ll binpow(ll x, int st){
	ll res = 1;
	while(st > 0){
		if(st&1) res = (res * x) % mod;
		st >>= 1;
		x = (x * x) % mod;
	}
	return res;
}
void solve(){
	scanf("%d%d", &n, &m);
	int X = 0;
	int Y = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 0) X++;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
		if(b[i] == 0) Y++;
	}
	int c = 0;
	ll ans = 0;
	ll q = binpow(m, X) * binpow(m, Y) % mod;
	for(int i = 0; i < n; i++){
		if(a[i] == 0 && b[i] == 0){
			X--;
			Y--;

			ll D = m-1;
			D *= m;
			D/=2;
			D %= mod;
			ans = (ans + binpow(m, c) * binpow(m, X) % mod * binpow(m, Y) % mod * D) % mod;
			c++;
		}else if(a[i] == 0){
			X--;
			ans = (ans + binpow(m, c) * binpow(m, X) % mod * binpow(m, Y) % mod * (m - b[i])) % mod;
		}else if(b[i] == 0){
			Y--;
			ans = (ans + binpow(m, c) * binpow(m, X) % mod * binpow(m, Y) % mod * (a[i]-1)) % mod;
		}else if(a[i] > b[i]){
			ans = (ans + binpow(m, c) * binpow(m, X) % mod * binpow(m, Y)) % mod;
			break;
		}else if(a[i] < b[i]) {
			break;
		}
	}
	cout << ans * binpow(q, mod-2) % mod<<endl;
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