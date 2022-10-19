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
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define LAST(v) (v)[SZ(v)-1]
#define SZ(v) ((int) (v).size())
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const ll MOD = 998244353;
const int MN = 1e5 + 5;
const int BLK = 250;
int t, n;
vector<pair<int, ll>> dpPrev, dpNext;

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        dpPrev.clear();
        dpNext.clear();
        dpPrev.pb({0, 0});
        ll total = 0;

        for (int i = 0; i < n; i++) {
            int a; cin >> a;

            int prvPtr = 0;

            for (int j = 1; j <= BLK; j++) {
                int d = (a+j-1)/j;
                if(j > 1 && d == (a+j-2)/(j-1)) continue;
                int ce = (a+d-1)/d;
                int fl = a/d;
                assert(ce <= j && (d == 1 || (a+d-2)/(d-1) > j));

                assert(SZ(dpPrev));
                if(dpPrev[prvPtr].fs > fl) continue;
                while(prvPtr < SZ(dpPrev)-1 && dpPrev[prvPtr+1].fs <= fl) prvPtr++;
                dpNext.pb({ce, (dpPrev[prvPtr].sn + (ll)(d-1)*(i+1)) % MOD});
            }

            for (int d = (a+BLK-1)/BLK - 1; d > 0; d--) {
                int ce = (a+d-1)/d;
                int fl = a/d;

                assert(SZ(dpPrev));
                if(dpPrev[prvPtr].fs > fl) continue;
                while(prvPtr < SZ(dpPrev)-1 && dpPrev[prvPtr+1].fs <= fl) prvPtr++;
                dpNext.pb({ce, (dpPrev[prvPtr].sn + (ll)(d-1)*(i+1)) % MOD});
            }

            swap(dpPrev, dpNext);
            dpNext.clear();
            total += LAST(dpPrev).sn;
            total %= MOD;
        }

        cout << total << '\n';
    }
}