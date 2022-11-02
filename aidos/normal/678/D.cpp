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


int binpow(int x, ll st){
	if(st == 0) return 1;
	if(st %2 == 0) return binpow(x * 1ll * x % mod, st/2);
	return binpow(x, st-1) * 1ll * x % mod;
}
int a, b, x;
ll n;
void solve(){
	scanf("%d %d %lld %d", &a, &b, &n, &x);
	ll sum = binpow(a, n) * 1ll * x % mod;
	if(a == 1){
		sum = (sum + n % mod * 1ll * b % mod) % mod;
	}else{
		sum = (sum + (binpow(a, n) - 1 + mod) % mod * 1ll *binpow(a-1, mod-2) % mod * 1ll * b % mod) % mod;
	}
	printf("%lld\n", sum);

}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}