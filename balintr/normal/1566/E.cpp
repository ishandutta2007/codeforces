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
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 2e5 + 5;
int t, n;
vi adjList[MN];
vi arr;

// Returns whether remaining
bool dfs(int n1, int par){
    int numRem = 0;
    for(int n2 : adjList[n1]){
        if(n2 == par) continue;
        numRem += dfs(n2, n1);
    }
    if(numRem){
        arr.pb(numRem);
        return false;
    }
    return true;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; ++i) {
            adjList[i].clear();
        }
        for (int i = 0; i < n-1; ++i) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }

        arr.clear();
        dfs(0, -1);
        int ans = 0;
        for(int a : arr){
            ans += a;
        }
        ans -= arr.size() - 1;
        cout << ans << '\n';
    }
}