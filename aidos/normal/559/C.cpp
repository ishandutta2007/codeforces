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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;


using namespace std;
int mod = 1000000007;
vector < pii > vi;
int h, w, n;
int fact[200100];
int dp[5010];

int binpow(ll a, int c){
    if( c == 0) return 1;
    if( c % 2 ) return binpow(a, c-1) * 1ll * a % mod;
    return binpow(a * 1ll * a % mod, c/2);
}
int get(int n, int m){
    return fact[n] * 1ll * binpow(fact[m] * 1ll * fact[n - m] % mod, mod-2) % mod;
}

int go(int pos){
    int &res = dp[pos];
    if( res != -1) return res;
    res = get(vi[pos].f + vi[pos].s, vi[pos].s);

    for(int i = 0; i < pos; i++){
        if( vi[pos].f >= vi[i].f && vi[pos].s >= vi[i].s){           
            
            res -= get(vi[pos].f - vi[i].f + vi[pos].s-vi[i].s, vi[pos].s - vi[i].s) * 1ll * go(i) % mod;
            if( res < 0){
                res += mod;
            }
        }
    }

    return res;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    fact[0] = 1;
    for(int i = 1; i < 200010; i++)
        fact[i] = fact[i-1] * 1ll * i % mod;
    cin >> h >> w >> n;
    vi.pb(mp(h-1, w-1));
    for(int i = 0; i < n; i++){
        cin >> h >> w;
        vi.pb(mp(h-1, w-1));
    }
    memset(dp, -1, sizeof dp);
    sort(vi.begin(), vi.end());
    cout << go(n) << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}