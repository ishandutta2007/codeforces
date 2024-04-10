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

const int MN = 2e5 + 5;
int t, n, k;
vi adjList[MN];
bool fri[MN];
pii dp[MN];

void dfs(int n1, int par, int dist){
    if(fri[n1]){
        dp[n1] = {(dist+1)/2, 1};
        return;
    }
    if(SZ(adjList[n1]) - (par != -1) == 0){
        dp[n1] = {INF, -1};
        return;
    }

    bool pos = true;
    for(int n2 : adjList[n1]){
        if(n2 == par) continue;
        dfs(n2, n1, dist+1);
        dp[n1].fs = min(dp[n1].fs, dp[n2].fs);
        dp[n1].sn += dp[n2].sn;
        if(dp[n2].sn == -1) pos = false;
    }
    if(dp[n1].fs <= dist) dp[n1].sn = 1;
    else if(!pos) dp[n1].sn = -1;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            adjList[i].clear();
            fri[i] = false;
            dp[i] = {INF, 0};
        }

        for (int i = 0; i < k; i++) {
            int a; cin >> a; a--;
            fri[a] = true;
        }
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }

        dfs(0, -1, 0);
        cout << (dp[0].sn == -1 ? "YES\n" : "NO\n");
    }
}