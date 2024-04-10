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
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

template <typename T, int MSZ>
struct BIT {
    int sz;
    T data[MSZ+1];

    void init(int inSz){
        sz = inSz;
    }

    inline void update(int i, T x){
        for (++i; i <= sz; i += i & -i) data[i] += x;
    }

    // Sum of [0, i]
    inline T query(int i){
        T res = 0;
        for (++i; i > 0; i -= i & -i) res += data[i];
        return res;
    }
};

const int MN = 5005;
int t, n;
int arr[MN];

void solve(){
    ll ans = 0;
    cin >> n;
    FR(i, n) cin >> arr[i], arr[i]--;

    BIT<int, MN> prefBit{};
    prefBit.init(n);

    FR(i, n){
        BIT<int, MN> sufBit{};
        sufBit.init(n);

        FORR(j, n-1, i+1){
            int v1 = prefBit.query(arr[j]);
            int v2 = sufBit.query(arr[i]);
            ans += v1*v2;
            sufBit.update(arr[j], 1);
        }
        prefBit.update(arr[i], 1);
    }

    cout << ans << '\n';
}

int main(){
    boost();
    cin >> t;
    while(t--) solve();
}