#include <bits/stdc++.h>
using namespace std;
#define LOCAL 0
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

#if LOCAL
const int MN = 10000;
#else
const int MN = 5e6 + 5;
#endif

int n;
int freq[MN], numMultInArr[MN];
ll bestPrv[MN];

int main(){
    boost();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a]++;
    }
    for (int i = 2; i < MN; i++) {
        for (int j = i; j < MN; j += i) {
            numMultInArr[i] += freq[j];
        }
        bestPrv[i] = n - numMultInArr[i];
    }
    ll ans = 0;
    for (int i = 2; i < MN; i++) {
        ans = max(ans, bestPrv[i] + (ll) numMultInArr[i]*i);
        for (int j = i+i; j < MN; j += i){
            bestPrv[j] = max(bestPrv[j], bestPrv[i] + (ll) i * (numMultInArr[i] - numMultInArr[j]));
        }
    }
    cout << ans << '\n';
}