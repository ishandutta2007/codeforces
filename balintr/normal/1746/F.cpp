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

const int S = 30;
const int MN = 3e5 + 5;
int n, q;
int arr[MN], bit[S][MN];
bitset<MN*2> inSet[S];
tuple<int, int, int> events[MN];
mt19937_64 rng;
vi compr;

int main(){
    boost();
    cin >> n >> q;
    FR(i, n) cin >> arr[i], compr.pb(arr[i]);

    FR(i, q){
        int t, l, r = -1, v;
        cin >> t >> l;
        if(t == 1) cin >> v, compr.pb(v);
        else cin >> r >> v;
        events[i] = {l, r, v};
    }

    UNIQUE(compr);

    rng.seed(chrono::high_resolution_clock::now().time_since_epoch().count() + (ll) new int);
    FR(i, S) FR(j, SZ(compr)) inSet[i][j] = rng() & 1;

    FR(i, n) arr[i] = lbv(compr, arr[i]);

    FR(i, S) FR(j, n){
        int p = j+1;
        if(inSet[i][arr[j]]) bit[i][p]++;
        int nxt = p + (p & -p);
        if(nxt <= n) bit[i][nxt] += bit[i][p];
    }

    FR(qi, q){
        auto [l, r, v] = events[qi];
        l--;

        if(r == -1){
            v = lbv(compr, v);
            FR(i, S){
                int dif = inSet[i][v] - inSet[i][arr[l]];
                for(int j = l+1; j <= n; j += j & -j) bit[i][j] += dif;
            }
            arr[l] = v;
        }
        else {
            bool good = (r-l) % v == 0;
            FR(i, S){
                int sum = 0;
                for(int j = r; j; j -= j & -j) sum += bit[i][j];
                for(int j = l; j; j -= j & -j) sum -= bit[i][j];
                good &= sum % v == 0;
            }
            cout << (good ? "YES\n" : "NO\n");
        }
    }
}