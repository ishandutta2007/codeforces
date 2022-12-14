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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct edge{
    int u, v;
    ll to(ll x){
        return (x == u ? v : u);
    }
};

ll ans[MAXN], dp[MAXN];

bool f[MAXN];

vector <pll> v[MAXN];
vector <ll> g[MAXN], vc[MAXN];

edge e[MAXN];

ll p[MAXN], kol[MAXN];

ll get(ll x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m, k, q;
    cin >> n >> m >> k >> q;

    vector <pair <ll, pll>> graph_edge(m);

    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].p_b({b, c});
        v[b].p_b({a, c});
        graph_edge[i].fi = c;
        graph_edge[i].se = {a, b};
    }

    for(int i = 0; i < q; i++){
        cin >> e[i].u >> e[i].v;
        g[e[i].u].p_b(i);
        g[e[i].v].p_b(i);
    }

    priority_queue <pll> st;

    for(int i = 1; i <= n; i++){
        dp[i] = inf;
        if(i <= k){
            dp[i] = 0;
            st.push({0, i});
        }
    }

    while(!st.empty()){
        pll xe = st.top();
        st.pop();
        if(f[xe.se])continue;
        f[xe.se] = 1;
        for(auto i : v[xe.se]){
            ll val1 = -xe.fi + i.se, to = i.fi;
            if(dp[to] > val1){
                dp[to] = val1;
                st.push({-dp[to], to});
            }
        }
    }

    for(int i = 0; i < m; i++){
        graph_edge[i].fi += dp[graph_edge[i].se.fi] + dp[graph_edge[i].se.se];
    }

    sort(all(graph_edge));

    for(int i = 1; i <= n; i++){
        p[i] = i;
        kol[i] = sz(g[i]);
        vc[i].p_b(i);
    }

    for(auto j : graph_edge){
        ll ra = j.se.fi, rb = j.se.se, cost = j.fi;

        if(get(ra) != get(rb)){
            ra = get(ra), rb = get(rb);
            if(kol[ra] > kol[rb])swap(ra, rb);
            p[ra] = rb;
            for(auto i : vc[ra]){
                for(auto j : g[i]){
                    if(get(e[j].to(i)) == get(i)){
                        if(!ans[j])ans[j] = cost;
                    }
                }
                vc[rb].p_b(i);
            }
            kol[rb] += kol[ra];
            vc[ra].clear();
        }

    }

    for(int i = 0; i < q; i++)cout << ans[i] << "\n";

    return 0;
}