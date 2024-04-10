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
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct node{
    ll val;
    node *l, *r;
    node(): val(0), l(r=nullptr){}
};

node *root2 = new node();

ll Val(node *v){
    if(v == nullptr)return 0;
    return v -> val;
}

void modify(node *v, int tl, int tr, int pos, int val){
    if(tl == tr)v -> val += val;
    else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            if(v -> l == nullptr)v -> l = new node();
            modify(v -> l, tl, tm, pos, val);
        }else{
            if(v -> r == nullptr)v -> r = new node();
            modify(v -> r, tm + 1, tr, pos, val);
        }
        v -> val = Val(v -> l) + Val(v -> r);
    }
}

ll get(node *v, int tl, int tr, int l, int r){
    if(l > r)return 0;
    if(v == nullptr)return 0;
    if(tl == l && tr == r)return v -> val;
    int tm = (tl + tr) >> 1;
    return get(v -> l, tl, tm, l, min(r, tm)) + get(v -> r, tm + 1, tr, max(l, tm + 1), r);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> a(n + 1), b(n + 1);
    ordered_set <int> S;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        S.insert(b[i]);
    }

    for(int i = 1; i <= n; i++)a[i] = S.order_of_key(b[i] + 1);

    reverse(a.begin() + 1, a.end());

    ll ans = 0;

    ordered_set <pii> s;

    int id = 0;

    for(int i = 1; i <= n; i++){
        s.insert({a[i], ++id});
        modify(root2, 1, 1e6, a[i], s.order_of_key({a[i], 0}));
        ans += get(root2, 1, 1e6, 1, a[i] - 1);
    }

    cout << ans << "\n";

    return 0;
}