#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

const ll mod = 998244353;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);                        
        //cin >> t;
    #endif     

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n % 2) {
            cout << "0\n";
        }else {            
            ll x = 1;
            n /= 2;
            for (int i = 1; i <= n; i++) (x *= i) %= mod;            
            x *= x;
            x %= mod;
            cout << x << "\n";
        }
    }
    
    return 0;
}