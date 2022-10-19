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

const int MN = 1e4 + 5;
int t, n;
int ans[MN];
int curT;

int query(int p){
    cout << "? " << p << endl;
    int res; cin >> res;
    return res;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        curT = 0;
        ms(ans, 0);

        cin >> n;
        for (int i = 1; i <= n; i++) {
            if(!ans[i]){
                vi vec;
                while(true){
                    int a = query(i);
                    curT++;
                    if(!vec.empty() && a == vec[0]) break;
                    vec.pb(a);
                }
                rotate(vec.begin(), find(ALL(vec), i), vec.end());
                rotate(vec.begin(), vec.begin()+1, vec.end());
                int p = i;
                for(int a : vec){
                    ans[p] = a;
                    p = a;
                }
            }
        }
        cout << '!';
        for (int i = 1; i <= n; i++) {
            cout << ' ' << ans[i];
        }
        cout << endl;
    }
}