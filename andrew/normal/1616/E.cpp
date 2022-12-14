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
const ll inf = 1e15;
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
        node(): l(r=nullptr), t(0){}

        void merge(){
            this -> t = 0;
            if(this -> l != nullptr) this -> t += (this -> l) -> t;
            if(this -> r != nullptr) this -> t += (this -> r) -> t;
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
    segment_tree<int> t(n);
    for(int i = 1; i <= n; i++){
        t.modify(i, 1);
    }
    ll ans = inf;
    ll su = 0;
    string a, b;
    cin >> a >> b;
    set <int> s[26];
    for(int i = 1; i <= n; i++){
        s[a[i - 1] - 'a'].insert(i);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < b[i - 1] - 'a'; j++){
            if(!s[j].empty()){
                int x = *s[j].begin();
                ans = min(ans, su + t.get(1, x) - 1);
            }
        }
        int x = b[i - 1] - 'a';
        if(s[x].empty()) break;
        int p = *s[x].begin();
        s[x].erase(s[x].begin());
        su += t.get(1, p) - 1;
        t.modify(p, 0);
    }
    if(ans == inf) ans = -1;    
    cout << ans << "\n";
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