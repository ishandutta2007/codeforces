/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */
 
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
 
ll q , n , found;
string s , x , y;
 
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
    cin >> q;
    while(q--){
        x = y = "";
        found = 0;
        cin >> n >> s;
        for(ll i = 0 ; i < n ; i++){
            ll A = s[i] - 48;
            if(found)   x.push_back(s[i]) , y.push_back('0');
            else if(A & 1){
                found = 1;
                x.push_back(A / 2 + 48);
                y.push_back(A / 2 + 49);
            }
            else{
                x.push_back(A / 2 + 48);
                y.push_back(A / 2 + 48);
            }
        }
        cout << x << endl << y << endl;
    }
 
    return 0;
}