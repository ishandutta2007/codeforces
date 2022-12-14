#include <bits/stdc++.h>

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 gen;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

struct node{
    pll Val;
    node *l, *r;
    node(): Val({0, 0}), l(r=nullptr){}
};

void modify(node *v, ll tl, ll tr, ll pos, pll val){
    v -> Val = max(v -> Val, val);
    if(tl != tr){
        ll tm = (tl + tr) >> 1;
        if(pos <= tm){
            if(v -> l == nullptr)v -> l = new node();
            modify(v -> l, tl, tm, pos, val);
        }else{
            if(v -> r == nullptr)v -> r = new node();
            modify(v -> r, tm + 1, tr, pos, val);
        }
    }
}

pll get(node *v, ll tl, ll tr, ll l, ll r){
    if(l > r)return {0, 0};
    if(v == nullptr)return {0, 0};
    if(tl == l && tr == r)return v -> Val;
    ll tm = (tl + tr) >> 1;
    return max(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}

ll dp[MAXN], pr[MAXN];

node *root = new node();

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, d;
    cin >> n >> d;

    vector <ll> h(n + 1);

    for(int i = 1; i <= n; i++)cin >> h[i];

    ll R = 1e15, L = 1;

    pll res = {0, 0};

    for(int i = 1; i <= n; i++){
        ll x = h[i], le = h[i] - d, ri = h[i] + d;
        pll xe = get(root, L, R, 1, le);
        xe = max(xe, get(root, L, R, ri, R));
        pr[i] = xe.se;
        dp[i] = xe.fi + 1;
        modify(root, L, R, h[i], {dp[i], i});
        res = max(res, {dp[i], i});
    }

    ll x = res.se;
    vector <ll> ans;

    while(x){
        ans.p_b(x);
        x = pr[x];
    }

    reverse(all(ans));

    cout << ans.size() << "\n";
    for(auto i : ans)cout << i << " ";
    cout << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}