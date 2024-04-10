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

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , timer , st[MAXN] , fn[MAXN] , seg[2][MAXN << 2] , lazy[MAXN << 2];
vector<ll> adj[MAXN];

void DFS(ll v , ll p = -1){
    st[v] = ++timer;
    for(ll u : adj[v])  if(p != u)  DFS(u , v);
    fn[v] = timer;
}

void Shift(int id){
    if(lazy[id] == 0)
        return;
    lazy[id << 1] = lazy[id];
    lazy[id << 1 | 1] = lazy[id];
    seg[0][id << 1] = lazy[id];
    seg[0][id << 1 | 1] = lazy[id];
    lazy[id] = 0;
}

void Update(int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql || r <= l || qr <= ql)    return;
    if(ql <= l && r <= qr){
        lazy[id] = x;
        seg[0][id] = x;
        return;
    }
    Shift(id);
    int mid = l + r >> 1;
    Update(ql , qr , x , id << 1 , l , mid);
    Update(ql , qr , x , id << 1 | 1 , mid , r);
}

int Get(int x , int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1)  return seg[0][id];
    Shift(id);
    int mid = l + r >> 1;
    if(x < mid) return Get(x , id << 1 , l , mid);
    return Get(x , id << 1 | 1 , mid , r);
}

void update(int x , int val , int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[1][id] = val;
        return;
    }
    int mid = l + r >> 1;
    if(x < mid) update(x , val , id << 1 , l , mid);
    else    update(x , val , id << 1 | 1 , mid , r);
    seg[1][id] = max(seg[1][id << 1] , seg[1][id << 1 | 1]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(r <= ql || qr <= l || r <= l || qr <= ql)    return -INF;
    if(ql <= l && r <= qr)  return seg[1][id];
    int mid = l + r >> 1;
    return max(get(ql , qr , id << 1 , l , mid) , get(ql , qr , id << 1 | 1 , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> n;
    for(ll i = 1 ; i < n ; i++){
        ll v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    DFS(1);

    cin >> q;
    for(ll i = 1 ; i <= q ; i++){
        ll c , v;
        cin >> c >> v;
        if(c == 1){
            Update(st[v] , fn[v] + 1 , i);
        }
        if(c == 2){
            update(st[v] , i);
        }
        if(c == 3){
            ll A = Get(st[v]) , B = get(st[v] , fn[v] + 1);
            if(B >= A)  cout << 0 << endl;
            else    cout << 1 << endl;
        }
    }

    return 0;
}
/*

*/