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
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MOD = 998244353;
const int MN = 5005;
int n, k;
bool arr[MN];
ll total = 1;

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

int main(){
    initFact();
    boost();
    cin >> n >> k;
    if(k == 0){
        cout << "1\n";
        return 0;
    }

    string str; cin >> str;
    for (int i = 0; i < n; i++) {
        arr[i] = str[i]-'0';
    }
    for (int i = 0; i < n; i++) {
        if(i != 0 && arr[i-1] != 1) continue;
        int num1s = 0;
        int lastOnePos = -1;
        for (int j = i; j < n; j++) {
            if(arr[j] == 1) lastOnePos = j, num1s++;
            if(num1s != k) continue;
            if(j != n-1 && arr[j+1] != 1) continue;
            ll dif = choose(j-i+1, k);
            if(i) dif -= choose(lastOnePos-i, k-1);
            else dif--;
            //cout << i << ' ' << j << ' ' << dif << endl;
            total += dif;
            total %= MOD;
        }
    }
    total += MOD;
    total %= MOD;
    cout << total << '\n';
}