#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const ll inf = -1e18;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
struct segment_tree{
    int _size;
    struct node{
        node *l, *r;
        T t;
        node(): l(r=nullptr), t(inf){}
 
        void merge(){
            this -> t = inf;
            if(this -> l != nullptr) this -> t = max((this -> l) -> t, this -> t);
            if(this -> r != nullptr) this -> t = max((this -> r) -> t, this -> t);
        }
 
    };
 
    node *root, *ra, *rb;
 
    segment_tree(int n){
        _size = n;
        root = build(1, n);
    };
 
    void modify(int pos, T val){
        modify(root, 1, _size, pos, val);
    }
 
    T get(int l, int r){
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
    void modify(node *v, int tl, int tr, int pos, T val){
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

void solve(){
    int n;
    cin >> n;
    vector <ll> a(n + 1), pref(n + 1);
    segment_tree<ll> t(n);    
    for(int i = 1; i <= n; i++){
        cin >> a[i];        
    }
    ll k;
    cin >> k;
    for(int i = 1; i <= n; i++){
        a[i] -= k;
        pref[i] = pref[i - 1] + a[i];
        t.modify(i, pref[i]);
    }
    ll last = 0, ans = 0;
    for(int i = 2; i <= n; i++){
        ll x = inf;
        if(last == 0) {
            x = 0;
            if(i > 2) x = max(x, t.get(1, i - 2));
        }else{
            x = max(x, t.get(last, i - 2));
        }                
        if(pref[i] - x < 0){
            last = i;               
            i++;        
            ans++;
        }
    }
    cout << n - ans << "\n";
}

int main(){

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //cin >> t;
    #endif    
    cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}