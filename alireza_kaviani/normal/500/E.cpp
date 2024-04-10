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

ll n , q , p[MAXN] , l[MAXN];
pll dp[LOG][MAXN];
int seg[MAXN << 2];

void modify(int x , int val , int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[id] = val;
        return;
    }
    int mid = l + r >> 1;
    if(x < mid) modify(x , val , id << 1 , l , mid);
    else    modify(x , val , id << 1 | 1 , mid , r);
    seg[id] = max(seg[id << 1] , seg[id << 1 | 1]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= ql || qr <= l || r <= ql || r <= l)    return 0;
    if(ql <= l && r <= qr)  return seg[id];
    int mid = l + r >> 1;
    return max(get(ql , qr , id << 1 , l , mid) , get(ql , qr , id << 1 | 1 , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> p[i] >> l[i];
    for(ll i = n + 1 ; i < MAXN ; i++)  dp[0][i].X = p[i] = INF;
    
    for(int i = n ; i >= 1 ; i--){
        dp[0][i].X = max(p[i] + l[i] , ll(get(i , upper_bound(p , p + MAXN , p[i] + l[i]) - p)));
        modify(i , dp[0][i].X);
    }

    for(ll i = 1 ; i < LOG ; i++){
        for(ll j = 0 ; j < MAXN ; j++){
            ll ind = upper_bound(p , p + MAXN , dp[i - 1][j].X) - p;
            if(ind < MAXN){
                dp[i][j].X = dp[i - 1][ind].X;
                dp[i][j].Y = dp[i - 1][j].Y + dp[i - 1][ind].Y + p[ind] - dp[i - 1][j].X;
            }
            else    dp[i][j] = dp[i - 1][j];
        }
    }

    cin >> q;
    while(q--){
        ll x , y , ans = 0;
        cin >> x >> y;
        for(ll i = LOG - 1 ; i >= 0 ; i--){
            if(dp[i][x].X < p[y])   ans += *upper_bound(p , p + MAXN , dp[i][x].X) - dp[i][x].X + dp[i][x].Y , x = upper_bound(p , p + MAXN , dp[i][x].X) - p;
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/