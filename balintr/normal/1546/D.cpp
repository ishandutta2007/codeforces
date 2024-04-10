#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 1e5 + 5;
const ll MOD = 998244353;

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
        return fact[a] * modInv(fact[b]) % MOD * modInv(fact[a-b]) % MOD;
    }
}
using namespace Mod;

int t, n;

int main(){
    boost();
    initFact();
    cin >> t;
    while(t--){
        string str;
        cin >> n >> str;
        int num2s = 0;
        int sub = 0;

        for (int i = 0; i < n; ++i) {
            if(str[i] == '1'){
                if(i+1 < n && str[i+1] == '1'){
                    num2s++;
                    i++;
                }
                sub++;
            }
        }

        cout << choose(n - sub, num2s) << '\n';
    }
}