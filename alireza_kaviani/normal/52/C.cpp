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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , A[MAXN] , q , seg[MAXN << 2] , lazy[MAXN << 2];

void build(int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[id] = A[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1 , l , mid) ; build(id << 1 | 1 , mid , r);
    seg[id] = min(seg[id << 1] , seg[id << 1 | 1]);
}

void Shift(int id){
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    seg[id << 1] += lazy[id];
    seg[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}

void update(int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql || r <= l || qr <= ql)    return;
    if(ql <= l && r <= qr){
        lazy[id] += x;
        seg[id] += x;
        return;
    }
    Shift(id);
    int mid = l + r >> 1;
    update(ql , qr , x , id << 1 , l , mid) ; update(ql , qr , x , id << 1 | 1 , mid , r);
    seg[id] = min(seg[id << 1] , seg[id << 1 | 1]);
}

ll get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql || r <= l || qr <= ql)    return INF;
    if(ql <= l && r <= qr)  return seg[id];
    Shift(id);
    int mid = l + r >> 1;
    return min(get(ql , qr , id << 1 , l , mid) , get(ql , qr , id << 1 | 1 , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    scanf("%I64d" , &n);
    for(ll i = 1 ; i <= n ; i++)    scanf("%I64d" , A + i);
    build();
    scanf("%I64d" , &q);
    while(q--){
        ll l , r;
        char c;
        scanf("%I64d%I64d" , &l , &r);
        l++ , r++;
        c = getchar();
        if(c == '\n'){
            if(l > r)   printf("%I64d\n" , min(get(l , n + 1) , get(1 , r + 1)));
            else    printf("%I64d\n" , get(l , r + 1));
        }
        else{
            ll x;
            scanf("%I64d" , &x);
            if(l > r)   update(l , n + 1 , x) , update(1 , r + 1 , x);
            else    update(l , r + 1 , x);
        }
    }

    return 0;
}
/*

*/