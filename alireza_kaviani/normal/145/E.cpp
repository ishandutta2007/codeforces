/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pld;
typedef pair<string, string> pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r" , stdin) ; freopen("out.txt" , "w" , stdout);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll input() {
    ll n;
    cin >> n;
    return n;
}

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct Node{
    ll LIS = 0 , LDS = 0 , cnt4 = 0 , cnt7 = 0, lazy = 0;
    Node(ll lis = 0 , ll lds = 0 , ll c4 = 0 , ll c7 = 0 , ll lzy = 0){
        LIS = lis;
        LDS = lds;
        cnt4 = c4;
        cnt7 = c7;
        lazy = lzy;
    }

    friend Node merge(const Node &x , const Node &y){
        return Node(max(x.LIS + y.cnt7 , x.cnt4 + y.LIS) , max(x.LDS + y.cnt4 , x.cnt7 + y.LDS) , x.cnt4 + y.cnt4 , x.cnt7 + y.cnt7);
    }
};

template<class T , ll N>
struct LazySegTree {
    T seg[4 * N];

    void Build(ll id, ll l, ll r, const string& s) {
        if (l == r) {
            if(l >= s.size())   return;
            if(s[l] == '4') seg[id] = Node(1 , 1 , 1 , 0);
            if(s[l] == '7') seg[id] = Node(1 , 1 , 0 , 1);
            return;
        }
        ll mid = (l + r) >> 1;
        Build(id * 2, l, mid, s);
        Build(id * 2 | 1, mid + 1, r, s);
        seg[id] = merge(seg[id * 2], seg[id * 2 | 1]);
    }

    void Shift(ll id, ll l, ll r) {
        if(!seg[id].lazy)   return;
        swap(seg[id].LIS , seg[id].LDS);
        swap(seg[id].cnt4 , seg[id].cnt7);
        if (l != r) {
            seg[id * 2].lazy ^= seg[id].lazy;
            seg[id * 2 | 1].lazy ^= seg[id].lazy;
        }
        seg[id].lazy = 0;
    }

    void Add(ll id, ll l, ll r, ll ql, ll qr, ll val) {
        Shift(id, l, r);
        if (qr < l || r < ql || l > r)  return;
        if (ql <= l && r <= qr) {
            seg[id].lazy ^= val;
            Shift(id, l, r);
            return;
        }

        ll mid = (l + r) >> 1;
        Add(id * 2, l, mid, ql, qr, val);
        Add(id * 2 | 1, mid + 1, r, ql, qr, val);
        seg[id] = merge(seg[id * 2], seg[id * 2 | 1]);
    }

    void build(string s){
        Build(1, 0, N - 1, s);
    }
    void add(ll ql, ll qr, ll val) {
        Add(1, 0, N - 1, ql, qr, val);
    }
};

ll n , q , l , r;
string s , type;
LazySegTree<Node , MAXN> seg;

int main() {
    fast_io;

    cin >> n >> q >> s;
    seg.build(s);

    while(q--){
        cin >> type;
        if(type[0] == 's'){
            cin >> l >> r;
            l--; r--;
            seg.add(l , r , 1);
        }
        else{
            cout << seg.seg[1].LIS << endl;
        }
    }

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/