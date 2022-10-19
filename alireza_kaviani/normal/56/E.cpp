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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
int ans[MAXN] , seg[MAXN << 2];
pair<pll , ll> p[MAXN];

void modify(int x , int val , int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[id] = max(seg[id] , val);
        return;
    }
    int mid = l + r >> 1;
    if(x < mid) modify(x , val , id << 1 , l , mid);
    else    modify(x , val , id << 1 | 1 , mid , r);
    seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql || r <= l || qr <= ql)    return -INF;
    if(ql <= l && r <= qr)  return seg[id];
    int mid = l + r >> 1;
    return max(get(ql , qr , id << 1 , l , mid) , get(ql , qr , id << 1 | 1 , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i].X.X >> p[i].X.Y , p[i].Y = i;
    for(ll i = 0 ; i < MAXN ; i++)  modify(i , i);
    
    sort(p + 1 , p + n + 1);
    for(ll i = n ; i >= 1 ; i--){
        modify(i , get(i , lower_bound(p + 1 , p + n + 1 , pair<pll , ll>({p[i].X.X + p[i].X.Y , -INF} , -INF)) - p));
        //cout << i << sep << lower_bound(p + 1 , p + n + 1 , pair<pll , ll>({p[i].X.X + p[i].X.Y , -INF} , -INF)) - p << endl;
        ans[p[i].Y] = get(i , i + 1) - i + 1;
    }
    for(ll i = 1 ; i <= n ; i++)    cout << ans[i] << sep;
    
    return 0;
}
/*

*/