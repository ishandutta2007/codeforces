#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 1e9;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct node{
    ll t, t1, c;
    node *l, *r;
    node(): t(t1=0), c(0), l(r=nullptr){}
};

node *root = new node();

ll mul(ll a, ll b){
    return (a * b) % mod;
}

void check(ll &x){
    if(x < 0) x += mod;
    if(x >= mod) x -= mod;
}

void push(node *v, ll la, ll lb){
    if(v -> t1 == -1) return;
    if(v -> l != nullptr){
        (v -> l) -> t = mul(v -> t1, la) + (v -> c % 2 == 0 ? (v -> l) -> t : -(v -> l) -> t);
        check((v -> l) -> t);
        if((v -> l) -> t1 == -1){
            (v -> l) -> t1 = v -> t1;
            (v -> l) -> c = v -> c;
        }else{
            (v -> l) -> t1 = v -> t1 + (v -> c % 2 == 0 ? (v -> l) -> t1 : -(v -> l) -> t1);
            check((v -> l) -> t1);
            (v -> l) -> c += v -> c;
        }
    }
    if(v -> r != nullptr){
        (v ->r) -> t = mul(lb, v -> t1) + (v -> c % 2 == 0 ? (v -> r) -> t : -(v -> r) -> t);
        check((v -> r) -> t);
        if((v -> r) -> t1 == -1){
            (v -> r) -> t1 = v -> t1;
            (v -> r) -> c = v -> c;
        }else{
            (v -> r) -> t1 = v -> t1 + (v -> c % 2 == 0 ? (v -> r) -> t1 : -(v -> r) -> t1);
            check((v -> r) -> t1);
            (v -> r) -> c += v -> c;
        }
    }
    v -> t1 = -1;
    v -> c = 0;
}

void modify(node *v, int tl, int tr, int l, int r, ll val){
    if(l > r) return;
    if(tl == l && tr == r){
        v -> t = mul(val, r - l + 1) - v -> t;
        check(v -> t);
        if(v -> t1 == -1){
            v -> t1 = val;
            v -> c = 1;
        }else{
            v -> t1 = val - v -> t1;
            check(v -> t1);
            v -> c ++;
        }        
        return;
    }
    int tm = (tl + tr) >> 1;
    if(v -> l == nullptr) v -> l = new node();
    if(v -> r == nullptr) v -> r = new node();
    push(v, tm - tl + 1, tr - tm);
    modify(v -> l, tl, tm, l, min(r, tm), val);
    modify(v -> r, tm + 1, tr, max(l, tm + 1), r, val);
    v -> t = 0;
    if(v -> l != nullptr){
        v -> t = (v -> l) -> t;
    }
    if(v -> r != nullptr){
        v -> t += (v -> r) -> t;
        if(v -> t >= mod) v -> t -= mod;
    }
}

bool erase(node *v, int tl, int tr, int l, int r){
    if(v == nullptr) return 0;
    if(l > r) return 0;
    if(tl == l && tr == r) return 1;
    int tm = (tl + tr) >> 1;
    if(v -> l == nullptr) v -> l = new node();
    if(v -> r == nullptr) v -> r = new node();
    push(v, tm - tl + 1, tr - tm);
    if(erase(v -> l, tl, tm, l, min(r, tm))) v -> l = nullptr;
    if(erase(v -> r, tm + 1, tr, max(l, tm + 1), r)) v -> r = nullptr;
    v -> t = 0;
    if(v -> l != nullptr){
        v -> t = (v -> l) -> t;
    }
    if(v -> r != nullptr){
        v -> t += (v -> r) -> t;
        if(v -> t >= mod) v -> t -= mod;
    }
    return 0;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    modify(root, 1, N, 1, a[1], 1);

    for(int i = 2; i <= n; i++){
        ll s = root -> t;        
        modify(root, 1, N, 1, a[i], s);
        erase(root, 1, N, a[i] + 1, N);
    }

    cout << root -> t << "\n";

    return 0;
}