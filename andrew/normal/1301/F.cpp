#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
const ll MAXN = 1123456;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll a[1010][1010];
int cost[1010][1010][41];

vector <pii> v[50];
bool f[51];
ll n, m, k;

void calc(ll x){
    for(int i = 1; i <= k; i++)f[i] = 0;
    queue <pii> q;
    for(auto i : v[x]){
        cost[i.fi][i.se][x] = 1;
        q.push({i.fi, i.se});
    }

    f[x] = 1;

    while(!q.empty()){
        pii xe = q.front();
        q.pop();
        if(!f[a[xe.fi][xe.se]]){
            f[a[xe.fi][xe.se]] = 1;
            for(auto i : v[a[xe.fi][xe.se]])if(!cost[i.fi][i.se][x]){
                cost[i.fi][i.se][x] = cost[xe.fi][xe.se][x] + 1;
                q.push(i);
            }
        }

        if(xe.fi > 1){
            if(!cost[xe.fi - 1][xe.se][x]){
                cost[xe.fi - 1][xe.se][x] = cost[xe.fi][xe.se][x] + 1;
                q.push({xe.fi - 1, xe.se});
            }
        }
        if(xe.se > 1){
            if(!cost[xe.fi][xe.se - 1][x]){
                cost[xe.fi][xe.se - 1][x] = cost[xe.fi][xe.se][x] + 1;
                q.push({xe.fi, xe.se - 1});
            }
        }
        if(xe.fi < n){
            if(!cost[xe.fi + 1][xe.se][x]){
                cost[xe.fi + 1][xe.se][x] = cost[xe.fi][xe.se][x] + 1;
                q.push({xe.fi + 1, xe.se});
            }
        }
        if(xe.se < m){
            if(!cost[xe.fi][xe.se + 1][x]){
                cost[xe.fi][xe.se + 1][x] = cost[xe.fi][xe.se][x] + 1;
                q.push({xe.fi, xe.se + 1});
            }
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            v[a[i][j]].p_b({i, j});
        }
    }

    for(int i = 1; i <= k; i++)calc(i);

    ll q;
    cin >> q;

    while(q--){
        ll x, y, x1, y1;
        cin >> x >> y >> x1 >> y1;
        int ans = abs(x - x1) + abs(y - y1);
        for(int color = 1; color <= k; color++)ans = min(ans, cost[x][y][color] + cost[x1][y1][color] - 1);
        cout << ans << "\n";
    }

    return 0;
}