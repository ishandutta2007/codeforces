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

const ll MAXN = 3.5e4 + 10;
const ll MAXK = 60;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , k , last[MAXN] , A[MAXN] , seg[MAXK][MAXN << 2] , lazy[MAXK][MAXN << 2];

void shift(int ind , int id){
    lazy[ind][id << 1] += lazy[ind][id];
    lazy[ind][id << 1 | 1] += lazy[ind][id];
    seg[ind][id << 1] += lazy[ind][id];
    seg[ind][id << 1 | 1] += lazy[ind][id];
    lazy[ind][id] = 0;
}

void update(int ind , int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql || qr <= ql)  return;
    if(ql <= l && r <= qr){
        lazy[ind][id] += x;
        seg[ind][id] += x;
        return;
    }
    shift(ind , id);
    int mid = l + r >> 1;
    update(ind , ql , qr , x , id << 1 , l , mid);
    update(ind , ql , qr , x , id << 1 | 1 , mid , r);
    seg[ind][id] = max(seg[ind][id << 1] , seg[ind][id << 1 | 1]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 0 ; j < MAXK ; j++){
            update(j , last[A[i]] , i , 1);
        }
        for(ll j = 1 ; j < MAXK ; j++){
            ll cur = seg[j - 1][1];
            update(j , i , i + 1 , cur);
        }
        last[A[i]] = i;
    }
    cout << seg[k - 1][1];

    return 0;
}
/*

*/