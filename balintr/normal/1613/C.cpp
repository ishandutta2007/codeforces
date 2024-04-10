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

const int MN = 105;
int t, n;
ll arr[MN], dArr[MN], h;

bool check(ll a){
    __int128 v = 0;
    for (int i = 0; i < n; i++) {
        v += min(dArr[i], a);
    }
    return v >= h;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> h;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n-1; i++) {
            dArr[i] = arr[i+1] - arr[i];
        }
        dArr[n-1] = 2e18;

        // Find the lowest number such that function is true, lo and hi are both inclusive
        ll lo = 0;
        ll hi = 1e18;
        while(lo < hi){
            ll mid = (lo + hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }
}