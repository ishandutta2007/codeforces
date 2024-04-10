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

const ll MAXN = 6e5 + 10;
const ll LOG = 22;
const ll INF = 2e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , L[MAXN] , R[MAXN] , K[MAXN];
vector<ll> compress;
int seg[MAXN << 2] , lazy[MAXN << 2] , sum[MAXN << 2];

void build(int id = 1 , int l = 0 , int r = n){
    if(r - l == 1){
        sum[id] = compress[r] - compress[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1 , l , mid) , build(id << 1 | 1 , mid , r);
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
}

void shift(int id){
    if(lazy[id] == -1)  return;
    lazy[id << 1] = lazy[id];
    lazy[id << 1 | 1] = lazy[id];
    seg[id << 1] = lazy[id] * sum[id << 1];
    seg[id << 1 | 1] = lazy[id] * sum[id << 1 | 1];
    lazy[id] = -1;
}

void update(int ql , int qr , int val , int id = 1 , int l = 0 , int r = n){
    if(qr <= l || r <= ql || qr <= ql)  return;
    if(ql <= l && r <= qr){
        lazy[id] = val;
        seg[id] = val * sum[id];
        return;
    }
    shift(id);
    int mid = l + r >> 1;
    update(ql , qr , val , id << 1 , l , mid);
    update(ql , qr , val , id << 1 | 1 , mid , r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(lazy , lazy + MAXN * 4 , -1);

    cin >> n >> q;
    for(ll i = 0 ; i < q ; i++){
        cin >> L[i] >> R[i] >> K[i];
        compress.push_back(L[i]);
        compress.push_back(R[i] + 1);
        K[i]--;
    }
    compress.push_back(1);
    compress.push_back(n + 1);
    Sort(compress);
    compress.resize(unique(all(compress)) - compress.begin());
    n = SZ(compress);
    compress.push_back(INF);
    build();
    update(0 , n - 1 , 1);
    for(ll i = 0 ; i < q ; i++){
        update(lower_bound(all(compress) , L[i]) - compress.begin() , lower_bound(all(compress) , R[i] + 1) - compress.begin() , K[i]);
        cout << seg[1] << endl;
    }

    return 0;
}
/*

*/