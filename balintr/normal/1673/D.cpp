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

const int MOD = 1e9 + 7;
int t;

ll solve(){
    int b0, bd, bn;
    cin >> b0 >> bd >> bn;
    int c0, cd, cn;
    cin >> c0 >> cd >> cn;
    ll bLst = b0 + (ll) bd*(bn-1);
    ll cLst = c0 + (ll) cd*(cn-1);

    if((c0 - b0) % bd) return 0;
    if(cd % bd) return 0;
    if(c0 < b0 || cLst > bLst) return 0;

    vi facts;
    for(int i = 1; i*i <= cd; i++){
        if(cd % i == 0){
            facts.pb(i);
            facts.pb(cd/i);
            if(i*i == cd) facts.pop_back();
        }
    }

    ll ans = 0;
    for(int ad : facts){
        if(lcm((ll) ad, bd) != cd) continue;
        if(c0 - cd < b0 || cLst + cd > bLst) return -1;
        ll val = cd/ad;
        ans = (ans + val*val) % MOD;
    }
    return ans;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}