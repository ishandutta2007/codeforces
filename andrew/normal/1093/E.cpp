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

sset <ll> T[MAXN];

ll pos[MAXN];
ll n;

void ins(ll x, ll val){
    for(int i = x; i <= n; i += i & -i)T[i].insert(val);

}

void er(ll x, ll val){
    for(int i = x; i <= n; i += i & -i)T[i].erase(val);

}

ll le, ri;

ll f(ll x){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i){
        res += T[i].order_of_key(ri + 1) - T[i].order_of_key(le);
    }
    return res;
}

ll get(ll l, ll r){
    return f(r) - f(l - 1);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll m;
    cin >> n >> m;

    vector <ll> b(n + 1);

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        pos[x] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
        ins(pos[b[i]], i);
    }

    while(m--){
        ll type;
        cin >> type;
        if(type == 1){
            ll l, r;
            cin >> l >> r >> le >> ri;

            cout << get(l, r) << "\n";

        }else {
            ll x, y;
            cin >> x >> y;
            er(pos[b[x]], x);
            er(pos[b[y]], y);
            swap(b[x], b[y]);
            ins(pos[b[x]], x);
            ins(pos[b[y]], y);
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}