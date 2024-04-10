#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int , int> pii;
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

ll n , q , A[MAXN];
pii seg[MAXN << 2];

pii merge(pii A , pii B){
    return pii(__gcd(A.X , B.X) , (A.X == __gcd(A.X , B.X)) * A.Y + (B.X == __gcd(A.X , B.X)) * B.Y);
}

void build(int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[id] = {A[l] , 1};
        return;
    }
    int mid = l + r >> 1;
    build(id << 1 , l , mid) ; build(id << 1 | 1 , mid , r);
    seg[id] = merge(seg[id << 1] , seg[id << 1 | 1]);
}

pii get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return seg[0];
    if(ql <= l && r <= qr)  return seg[id];
    int mid = l + r >> 1;
    return merge(get(ql , qr , id << 1 , l , mid) , get(ql , qr , id << 1 | 1 , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
    build();

    cin >> q;
    while(q--){
        ll l , r;
        cin >> l >> r;
        cout << r - l + 1 - get(l , r + 1).Y << endl;
    }

    return 0;
}
/*

*/