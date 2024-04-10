#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "Ofast"

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

#ifdef WIN32
const int MN = 5e5 + 5;
#else
const int MN = 2e7 + 5;
#endif

int n;
bitset<MN> isComp;
int primes[MN/10], pi, freq[MN], numMultInArr[MN];
ll best[MN];

int main(){
    boost();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a]++;
    }
    for (int i = 2; i < MN; i++) {
        if(isComp[i]) continue;
        primes[pi++] = i;
        for(int j = i; j < MN; j += i) isComp[j] = true;
    }
    for (int i = 2; i < MN; i++) {
        for (int j = i; j < MN; j += i) {
            numMultInArr[i] += freq[j];
        }
    }
    ll ans = 0;
    for (int i = MN-1; i > 1; i--) {
        best[i] = (ll) i * numMultInArr[i];
        for (int p = 0; i*primes[p] < MN; p++) {
            int j = i*primes[p];
            best[i] = max(best[i], best[j] + (ll) i * (numMultInArr[i] - numMultInArr[j]));
        }
        ans = max(ans, best[i] + n - numMultInArr[i]);
    }
    cout << ans << '\n';
}