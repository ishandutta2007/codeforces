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
#define fout(x) {cout << x << endl;return;}

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int N = 2e5;
const ll inf = 1e18;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN], cnt, g[MAXN], order, used, c;

int r;

void dfs(ll x){
    if(used[x])return;
    used[x] = 1;
    for(auto to : v[x])dfs(to);
}

void top_sort(ll x){
    if(used[x])return;
    used[x] = 1;
    for(auto to : v[x])top_sort(to);
    order.p_b(x);
}

void build_component(ll x){
    if(used[x]){
        if(c[x] != r)cnt[c[x]] = inf;
        return;
    }
    used[x] = 1;
    c[x] = r;
    cnt[r]++;
    for(auto to : g[x])build_component(to);
}

void main_solve(){
    ll n, m, h;
    cin >> n >> m >> h;
    vector <ll> u(n + 1);
    cnt.clear();
    cnt.resize(n + 1);
    c.clear();
    c.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> u[i];
        v[i].clear();
    }

    while(m--){
        ll a, b;
        cin >> a >> b;
        if((u[a] + 1) % h == u[b]){
            v[a].p_b(b);
            g[b].p_b(a);
        }
        if((u[b] + 1) % h == u[a]){
            v[b].p_b(a);
            g[a].p_b(b);
        }
    }

    used.clear();
    used.resize(n + 1);
    for(int i = 1; i <= n; i++){
        if(!used[i])top_sort(i);
    }

    reverse(all(order));

    used.clear();
    used.resize(n + 1);

    r = 0;

    for(auto i : order)if(!used[i]){
        r++;
        build_component(i);
    }


    pll ans = {n + 1, 0};

    for(int i = 1; i <= n; i++)ans = min(ans, {cnt[c[i]], i});

    used.clear();
    used.resize(n + 1);
    dfs(ans.se);
    cout << ans.fi << "\n";
    for(int i = 1; i <= n; i++)if(used[i])cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ll t;
        cin >> t;
        for(int id = 1; id <= t; id++){
            cout << "Test number " << id << ":\n";
            main_solve();
        }
    #else
        main_solve();
    #endif // LOCAL



    return 0;
}