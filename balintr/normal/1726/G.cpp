#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

const int MOD = 998244353;
const int MN = 2e5 + 5;

namespace Mod {
    ll fact[MN];

    void initFact(){
        fact[0] = 1;
        for (int i = 1; i < MN; ++i) {
            fact[i] = fact[i-1] * i % MOD;
        }
    }

    ll fpow(ll a, ll b){
        ll res = 1;
        ll pw2 = a;
        while(b){
            if(b & 1) res = (res * pw2) % MOD;
            pw2 = (pw2 * pw2) % MOD;
            b >>= 1;
        }
        return res;
    }

    inline ll modInv(ll a){
        return fpow(a, MOD - 2);
    }

    inline ll choose(ll a, ll b){
        return fact[a] * modInv(fact[b]) % MOD * modInv(fact[a - b]) % MOD;
    }
}
using namespace Mod;

int n;
pair<int, bool> arr[MN];
int freq[MN][2];

int main(){
    boost();
    initFact();
    cin >> n;
    FR(i, n) cin >> arr[i].fs;
    FR(i, n) cin >> arr[i].sn;
    int mn = min_element(arr, arr + n)->fs;

    FR(i, n) freq[arr[i].fs-mn][arr[i].sn]++;

    if(freq[0][0] + freq[0][1] == n) return !printf("%lld\n", fact[n]);

    ll ans = 1;
    int pref = 0;

    FR(i, n){
        if(freq[i][0]){
            int req = n-1 - i;
            if(pref < req) return !printf("0\n");
            pref += freq[i][0];
            ans = ans * fact[freq[i][0]] % MOD;
        }
        if(freq[i][1]){
            if(i == n-1) ans = ans * fact[n] % MOD * modInv(fact[pref]) % MOD;
            else if(freq[i][1] > 1) return !printf("0\n");
            pref += freq[i][1];
        }
    }

    assert(pref == n);
    cout << ans << '\n';
}