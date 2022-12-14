#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 1e9 + 7;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct segment_tree{
    int _size;
    struct node{
        node *l, *r;
        pii t;
        node(): l(r=nullptr), t({0, 0}){}

        void merge(){
            this -> t = {0, 0};
            if(this -> l != nullptr) {                
                this -> t = max(this -> t, this -> l -> t);
            }
            if(this -> r != nullptr) {
                this -> t = max(this -> t, this -> r -> t);
            }
        }

    };

    node *root, *ra, *rb;

    segment_tree(int n){} ;

    void build() {
        root = build(1, _size);
    }

    void modify(int pos, pii val){
        modify(root, 1, _size, pos, val);
    }

    pii get(int l, int r){
        ra = new node();
        rb = new node();
        get(root, 1, _size, l, r);
        return rb -> t;        
    }

private:
    static node* build(int tl, int tr){
        node *x = new node();
        if(tl != tr){
            int tm = (tl + tr) >> 1;
            x -> l = build(tl, tm);
            x -> r = build(tm + 1, tr);
            x -> merge();
        }
        return x;
    }
    void modify(node *v, int tl, int tr, int pos, pii val){
        if(tl == tr){
            v -> t = val;
        }else{
            int tm = (tl + tr) >> 1;
            if(pos <= tm){
                modify(v -> l, tl, tm, pos, val);
            }else{
                modify(v -> r, tm + 1, tr, pos, val);
            }
            v -> merge();
        }
    }
    void get(node *v, int tl, int tr, int l, int r){
        if(l > r) return;
        if(tl == l && tr == r){
            ra -> l = rb;
            ra -> r = v;
            ra -> merge();
            swap(ra, rb);
            return;
        }
        int tm = (tl + tr) >> 1;
        get(v -> l, tl, tm, l, min(r, tm));
        get(v -> r, tm + 1, tr, max(l, tm + 1), r);
    }
};

segment_tree t(300000);

int n, m;

vector<ll> calc(int l, int r) {
    if (l == r) {
        return vector <ll> (m, 1);
    }
    vector <ll> v(m, 0), lv(m), rv(m);

    int pos = -t.get(l, r).se;
    if (pos == l) {
        for (auto &i : lv) i = 1;
    }else {
        lv = calc(l, pos - 1);
        for (int i = 1; i < m; i++) {
            (lv[i] += lv[i - 1]) %= mod;
        }
    }
    if (pos == r) {
        for (auto &i : rv) i = 1;
    }else {
        rv = calc(pos + 1, r);
        for (int i = 1; i < m; i++) {
            (rv[i] += rv[i - 1]) %= mod;
        }
    }    

    for (int i = 0; i < m; i++) {
        if (i == 0) {
            if (l == pos) v[i] = rv[i];
        }else{
            v[i] = (lv[i - 1] * rv[i]) % mod;
        }
    }

    return v;
}

void solve(){
    cin >> n >> m;
    t._size = n;
    t.build();
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        t.modify(i, {x, -i});
    }
    vector <ll> v = calc(1, n);
    ll s = 0;
    for (auto &i : v) (s += i) %= mod;
    cout << s << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    
    cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}