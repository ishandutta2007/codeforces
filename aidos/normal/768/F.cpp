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
int n, m, h;
int fact[300300];
int rev[300300];
const int mod = 1000000007;

int binpow(int x,int y){
	int res = 1;
	while(y>0){
		if(y&1){
			res = (res * 1ll * x) % mod;
		}
		x = (x * 1ll * x) % mod;
		y >>= 1;
	}
	return res;
}
ll C(int x, int y){
	if(y < 0) return 0;
	if(x < y) return 0;
	return fact[x] * 1ll * rev[y] % mod * 1ll * rev[x - y] % mod;
}
void solve(){
	cin >> n >> m >> h;
	if(m <= h && m){
		cout << 0 << endl;
		return;
	}
	if(!n || !m){
		cout << 1 << endl;
		return;
	}
	fact[0] = 1;
	rev[0] = 1;
	for(int i=  1; i < 300100; i++){
		fact[i] = (fact[i-1]* 1ll * i ) % mod;
		rev[i] = binpow(fact[i], mod-2);
	}
	ll q = 0;
	ll p = 0;
	for(int i = 1; i <= 100000; i++){
		ll x = m - i * 1ll * h;
		q = (q +( C(n-1,i-2) + 2ll * C(n-1, i - 1) + C(n-1, i)) % mod * 1ll * C(m-1, i-1) % mod) % mod;
		if(x < 0) continue;
		p=((C(n-1,i-2) +2ll* C(n-1, i - 1) + C(n-1, i)) % mod * 1ll * C(x-1, i-1)%mod + p) % mod;
	}
	cout << p * 1ll * binpow(q, mod-2)%mod << endl;
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