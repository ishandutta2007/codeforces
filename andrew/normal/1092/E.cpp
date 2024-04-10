#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

ll cmp[MAXN], m, root[MAXN];

vector <ll> v[MAXN];
ll r, col[MAXN];

ll result, sk[MAXN];

void paint(ll x){
    if(col[x])return;
    col[x] = r;

    for(auto to : v[x])paint(to);

}

ll dfs(ll x, ll pr){
    ll ans = 0;

    for(auto to : v[x])if(to != pr){
        ans = max(ans, dfs(to, x) + 1);
    }

    return ans;

}

void f(ll x, ll pr){

    sk[x] = 0;

    multiset <ll> s;

    for(auto to : v[x])if(to != pr){
        f(to, x);
        sk[x] = max(sk[x], sk[to] + 1);

        s.insert(sk[to] + 1);

    }

    result = max(result, sk[x]);

    if(s.size() > 1){
        ll sc = 0;

        for(int i = 0; i < 2; i++){
            sc += *(--s.end());
            s.erase(--s.end());
        }

        result = max(result, sc);

    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("teamwork.in","r",stdin);
    //freopen("balance.in","w",stdout);

    ll n, m;
    cin >> n >> m;

    while(m--){
        ll a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    for(int i = 1; i <= n; i++){
        if(!col[i]){
            r++;
            cmp[r] = 1e18;
            paint(i);
        }

        ll sc = dfs(i, 0ll);

        if(sc < cmp[col[i]]){
            cmp[col[i]] = sc;
            root[col[i]] = i;
        }

    }

    vector <pll> ans;

    vector <pll> kek(r);

    for(int i = 1; i <= r; i++){

        kek[i - 1] = m_p( cmp[i] , root[i]);
    }

    sort(all(kek));
    reverse(all(kek));

    ll rt = kek[0].se;

    for(int i = 1; i < r; i++){
        ans.p_b({rt, kek[i].se});
        v[rt].p_b(kek[i].se);
        v[kek[i].se].p_b(rt);
    }


    f(1ll, 0ll);

    cout << result << "\n";

    for(auto i : ans)cout << i.fi << " " << i.se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}