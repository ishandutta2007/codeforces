/** I can do this all day **/

#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"

//void add(int I, int value){seg[I += MAXN] = value;for (I >>= 1; I; I >>= 1){seg[I] = __gcd(seg[I << 1], seg[I << 1 | 1]);}}

//int query(int l, int r){int ans = seg[l + MAXN];for (l += MAXN, r += MAXN + 1; l < r; l >>= 1, r >>= 1){if(l & 1) ans = __gcd(ans, seg[l ++]);if(r & 1) ans = __gcd(ans, seg[-- r]);}return ans;}

const int MAXN = 1e6 + 10;
const int MAXN2 = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 8e18;
const int LOG = 23;

ll pw(ll a , ll b, ll mod)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % mod, b / 2, mod)) % mod : pw(a * a % mod, b / 2, mod))); }

int d[MAXN], ans, C[MAXN];

vector < int > G[MAXN];

void DFS(int v, int par)
{
        //cout << v << " " << par << endl;
        for(auto x : G[v])
        {
                //cout << x << " ";
        }
        //scout << endl << endl;
        int cnt = 1;
        for(auto u : G[v])
        {
                if(u == par)continue;
                while(cnt == C[v] || cnt == C[par])
                {
                        cnt++;
                }
                C[u] = cnt;
                DFS(u, v);
                cnt++;
        }
}

int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
            int a, b; cin >> a >> b;
            G[a].push_back(b); G[b].push_back(a);
            d[a]++; d[b]++;
    }
    ans = 3;
    for(int i = 1; i <= n; i++)
    {
            ans = max(ans, d[i] + 1);
    }
    cout << ans << endl;
    C[1] = 1;
    C[0] = 1;
    DFS(1, 0);
    for(int i = 1; i <= n; i++)
    {
            cout << C[i] << " ";
    }
    return 0;
}