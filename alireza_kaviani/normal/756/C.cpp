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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll q , x[MAXN];
int seg[MAXN << 2] , lazy[MAXN << 2];

void shift(int id){
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    seg[id << 1] += lazy[id];
    seg[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}

void update(int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return;
    if(ql <= l && r <= qr){
        lazy[id] += x;
        seg[id] += x;
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    update(ql , qr , x , id << 1 , l , mid);
    update(ql , qr , x , id << 1 | 1 , mid , r);
    seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
}

int get(int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1)  return l;
    shift(id);
    int mid = l + r >> 1;
    if(seg[id << 1 | 1] >= 1)   return get(id << 1 | 1 , mid , r);
    return get(id << 1 , l , mid);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        ll p , t;
        cin >> p >> t;
        update(0 , p + 1 , (t == 0 ? -1 : 1));
        if(t == 1)  cin >> x[p];
        ll ans = get();
        if(ans == 0)   cout << -1 << endl;
        else    cout << x[ans] << endl;
    }

    return 0;
}
/*

*/