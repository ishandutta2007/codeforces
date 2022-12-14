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

bool used[MAXN], f[MAXN];

vector <ll> v[MAXN];

void dfs(ll x, bool deep){
    if(used[x]){
        if(f[x] != deep)vout(-1);
        return;
    }
    f[x] = deep;
    used[x] = 1;
    for(auto to : v[x])dfs(to, deep ^ 1);
}

int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= n; i++)if(!used[i]){
        dfs(i, 1);
    }
    vector <ll> ans[2];

    for(int i = 1; i <= n; i++)ans[f[i]].p_b(i);

    cout << ans[0].size() << "\n";
    for(auto i : ans[0])cout << i << " ";cout << "\n";

    cout << ans[1].size() << "\n";
    for(auto i : ans[1])cout << i << " ";cout << "\n";

    return 0;
}