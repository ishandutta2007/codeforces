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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , A[MAXN] , sum[MAXN << 2] , mx[MAXN << 2];

void build(int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        sum[id] = mx[id] = A[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1 , l , mid) ; build(id << 1 | 1 , mid , r);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    mx[id] = max(mx[id << 1] , mx[id << 1 | 1]);
}

void modify(int x , int val , int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        sum[id] = mx[id] = val;
        return;
    }
    int mid = l + r >> 1;
    if(x < mid) modify(x , val , id << 1 , l , mid);
    else    modify(x , val , id << 1 | 1 , mid , r);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    mx[id] = max(mx[id << 1] , mx[id << 1 | 1]);
}

void update(int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql || mx[id] < x)   return;
    if(r - l == 1){
        sum[id] %= x , mx[id] %= x;
        return;
    }
    int mid = l + r >> 1;
    update(ql , qr , x , id << 1 , l , mid);
    update(ql , qr , x , id << 1 | 1 , mid , r);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    mx[id] = max(mx[id << 1] , mx[id << 1 | 1]);
}

ll get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return 0;
    if(ql <= l && r <= qr)  return sum[id];
    int mid = l + r >> 1;
    return get(ql , qr , id << 1 , l , mid) + get(ql , qr , id << 1 | 1 , mid , r);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
    build();

    while(q--){
        ll t , l , r , x;
        cin >> t >> l >> r;
        if(t == 1)  cout << get(l , r + 1) << endl;
        if(t == 2){
            cin >> x;
            update(l , r + 1 , x);
        }
        if(t == 3)  modify(l , r);
    }

    return 0;
}
/*

*/