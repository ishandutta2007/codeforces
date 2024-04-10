#include <bits/stdc++.h>
#include <ext/pb_ds/Tree_policy.hpp>
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

ll n , A[MAXN] , B[MAXN] , ans[MAXN];
Tree<ll> Tr1 , Tr2 , Tr3;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> n;
    for(ll i = 0 ; i < n ; i++) Tr1.insert(i) , Tr2.insert(i) , Tr3.insert(i);
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
    for(ll i = 1 ; i <= n ; i++)    cin >> B[i];
    for(ll i = 1 ; i <= n ; i++){
        ll x = Tr1.order_of_key(A[i]) , y = Tr2.order_of_key(B[i]);
        Tr1.erase(A[i]) , Tr2.erase(B[i]);
        A[i] = x , B[i] = y;
    }
    ll t = 0;
    for(ll i = n ; i >= 1 ; i--){
        ans[i] = (A[i] + B[i] + t) % (n - i + 1);
        if(A[i] + B[i] + t >= n - i + 1)    t = 1;
        else    t = 0;
    }
    for(ll i = 1 ; i <= n ; i++){
        cout << *Tr3.find_by_order(ans[i]) << sep;
        Tr3.erase(Tr3.find_by_order(ans[i]));
    }

    return 0;
}
/*

*/