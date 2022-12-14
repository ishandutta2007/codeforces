#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <ll> v[MAXN];

ll comp[MAXN], R, kol[MAXN];
bool f[MAXN];
set <ll> s;

void dfs(ll x){
    v[x].p_b(0);
    v[x].p_b(inf);
    comp[x] = R;
    kol[R]++;
    f[x] = 1;
    s.erase(x);
    sort(all(v[x]));
    for(int i = 1; i < int(v[x].size()); i++){
        while(s.upper_bound(v[x][i - 1]) != s.end() && *s.upper_bound(v[x][i - 1]) < v[x][i]){
            dfs(*s.upper_bound(v[x][i - 1]));
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll old = m;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= n; i++)s.insert(i);

    for(int i = 1; i <= n; i++)if(!f[i]){
        R++;
        dfs(i);
    }

    if(kol[1] * kol[2] + kol[2] * kol[3] + kol[1] * kol[3] != old)vout(-1);

    if(R != 3)vout(-1);

    for(int i = 1; i <= n; i++)cout << comp[i] << " ";
    cout << "\n";

    return 0;
}