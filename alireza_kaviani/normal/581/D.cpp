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
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

set_random;

const ll MAXN = 410;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll sum , ln , x[3] , y[3] , ind[3];
char ans[MAXN][MAXN];

void fil(ll x1 ,ll x2 ,ll y1 ,ll y2 , char c){
    for(ll i = x1 ; i <= x2 ; i++){
        for(ll j = y1 ; j <= y2 ; j++){
            ans[i][j] = c;
        }
    }
}

ll check(ll x1 ,ll x2 ,ll y1 ,ll y2){
    for(ll i = x1 ; i <= x2 ; i++){
        for(ll j = y1 ; j <= y2 ; j++){
            if(ans[i][j] != '*')    return 0;
        }
    }
    return 1;
}

int main() {
    fast_io;
    
    for(ll i = 0 ; i < 3 ; i++){
        cin >> x[i] >> y[i];
        sum += x[i] * y[i];
        if(x[i] > y[i]) swap(x[i] , y[i]);
    }
    
    while(ln * ln < sum)    ln++;
    if(ln * ln != sum || *max_element(y , y + 3) > ln)  return cout << -1 << endl , 0;
    
    for(ll i = 0 ; i < 8 ; i++){
        for(ll j = 0 ; j < 3 ; j++){
            if(i & (1 << j))    swap(x[j] , y[j]);
            ind[j] = j;
        }
        
        do{
            fil(0 , ln + 10 , 0 , ln + 10 , '*');
            for(ll i : ind){
                ll br = 0;
                for(ll j = 0 ; j < ln - x[i] + 1 ; j++){
                    for(ll k = 0 ; k < ln - y[i] + 1 ; k++){
                        if(check(j , j + x[i] - 1 , k , k + y[i] - 1)){
                            fil(j , j + x[i] - 1 , k , k + y[i] - 1 , 'A' + i);
                            br = 1;
                            break;
                        }
                    }
                    if(br)  break;
                }
            }
            
            ll empt = 0;
            for(ll i = 0 ; i < ln ; i++){
                for(ll j = 0 ; j < ln ; j++){
                    if(ans[i][j] == '*')    empt = 1;;
                }
            }
            if(empt)    continue;
            cout << ln << endl;
            for(ll i = 0 ; i < ln ; i++){
                for(ll j = 0 ; j < ln ; j++){
                    cout << ans[i][j];
                }
                cout << endl;
            }
            return 0;
        }while(next_permutation(ind , ind + 3));
        for(ll j = 0 ; j < 3 ; j++){
            if(i & (1 << j))    swap(x[j] , y[j]);
            ind[j] = j;
        }
    }
    cout << -1 << endl;
    
    return 0;
}
/*

*/