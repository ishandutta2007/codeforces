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
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 300;
int t, n, k;
bool used[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> k;
        ms(used, 0);
        vpii edges;
        vi unused;

        for (int i = 0; i < k; ++i) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            used[a] = true;
            used[b] = true;
            edges.pb({a, b});
        }

        for (int i = 0; i < 2*n; ++i) {
            if(!used[i]) unused.pb(i);
        }

        for (int i = 0; i < n-k; ++i) {
            int a = unused[i];
            int b = unused[i+n-k];
            edges.pb({a, b});
        }

        int total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                vpii points;
                points.pb({edges[i].fs, 0});
                points.pb({edges[i].sn, 0});
                points.pb({edges[j].fs, 1});
                points.pb({edges[j].sn, 1});
                sort(ALL(points));
                if(points[0].sn != points[1].sn && points[1].sn != points[2].sn) total++;
            }
        }
        cout << total << '\n';
    }
}