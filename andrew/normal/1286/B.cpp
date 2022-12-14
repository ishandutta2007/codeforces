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

vector <ll> v[MAXN];
ll ans[MAXN], S;
ll p[MAXN], c[MAXN];
vector <pll> t[MAXN];

void dfs(ll x){
    for(auto to : v[x])dfs(to);
    for(auto i : v[x]){
        for(auto j : t[i])t[x].p_b(j);
        t[i].clear();
    }
    if(sz(t[x]) < c[x])vout("NO");
    sort(all(t[x]));
    for(int i = 0; i < sz(t[x]); i++){
        if(i < c[x])ans[x] = max(ans[x], t[x][i].fi + 1);
        else{
            ans[t[x][i].se] += 2;
            t[x][i].fi += 2;
        }
    }
    t[x].p_b({ans[x], x});
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        ans[i] = 1;
        cin >> p[i] >> c[i];
        v[p[i]].p_b(i);
    }

    for(auto i : v[0])dfs(i);

    cout << "YES\n";
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";

    return 0;
}