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

const int MN = 3e5 + 5;
const int BSZ = 600;
int t, n, m;
int arr[MN], freq[MN];
vi compr;
vi restricts[MN];
vi smallVals[BSZ];
vpii bigVals;
bitset<MN> bits;

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            compr.pb(arr[i]);
        }
        UNIQUE(compr);
        for (int i = 0; i < n; i++) {
            arr[i] = lbv(compr, arr[i]);
            freq[arr[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if(!freq[i]) continue;
            if(freq[i] < BSZ) smallVals[freq[i]].pb(i);
            else bigVals.pb({i, freq[i]});
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a = lbv(compr, a);
            b = lbv(compr, b);
            restricts[a].pb(b);
            restricts[b].pb(a);
        }

        ll mx = 0;
        for (int a = 0; a < n; a++) {
            if(!freq[a]) continue;
            for(int v : restricts[a]) bits[v] = true;
            bits[a] = true;

            for (int i = 1; i < BSZ; i++) {
                for (int j = SZ(smallVals[i])-1; j >= 0; j--) {
                    int b = smallVals[i][j];
                    if(!bits[b]){
                        mx = max(mx, (ll) (compr[a] + compr[b]) * (freq[a]+i));
                        break;
                    }
                }
            }
            for(auto [b, f] : bigVals){
                if(!bits[b]){
                    mx = max(mx, (ll) (compr[a] + compr[b]) * (freq[a] + f));
                }
            }

            for(int v : restricts[a]) bits[v] = false;
            bits[a] = false;
        }
        cout << mx << '\n';

        fill(freq, freq + n, 0);
        compr.clear();
        bigVals.clear();
        for(int i = 0; i < n; i++) restricts[i].clear();
        for(int i = 0; i < BSZ; i++) smallVals[i].clear();
    }
}