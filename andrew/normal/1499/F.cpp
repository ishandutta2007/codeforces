#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e7;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int n, k;

vector <int> v[10000];

void u(ll &a, ll b){
    a += b;
    if(a >= mod)a -= mod;
}

ll mul(ll a, ll b){
    a *= b;
    if(a >= mod)a %= mod;
    return a;
}

int up[10000];

ll dp[5001][5001], dp1[5001];

void dfs(int x, int p){

    for(auto to : v[x])if(to != p){
        dfs(to, x);
        up[x] = max(up[x], up[to] + 1);
    }

    if(up[x] == 0){
        dp[x][0] = 1;
        return;
    }

    vector <pii> vc;

    for(auto to : v[x])if(to != p){
        vc.p_b({up[to], to});
    }

    sort(vc.rbegin(), vc.rend());

    dp[x][0] = 1;
    int mx = 0;

    for(auto to : vc){
        for(int i = 0; i <= mx; i++){
            for(int j = 0; j <= to.fi; j++){
                if(i + j + 1 <= k){
                    u(dp1[max(j + 1, i)], mul(dp[x][i], dp[to.se][j]));
                }
                u(dp1[i], mul(dp[x][i], dp[to.se][j]));
            }
        }
        mx = max(mx, to.fi + 1);
        for(int i = 0; i <= mx; i++){
            dp[x][i] = dp1[i];
            dp1[i] = 0;
        }
    }

}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    dfs(1, 0);

    ll ans = 0;

    for(int i = 0; i <= k; i++)u(ans, dp[1][i]);

    cout << ans << "\n";

    return 0;
}