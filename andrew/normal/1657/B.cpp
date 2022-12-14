#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

bool good(ll x) {
    ll c = sqrt(x);
    while (c * c < x) c++;
    while (c * c > x) c--;
    return (c * c == x);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);                        
        //cin >> t;
    #endif       

    cin >> t;
    
    while(t--) {
       ll n, B, x, y;
       cin >> n >> B >> x >> y;
       ll s = 0, ans = 0;
       for (int i = 1; i <= n; i++) {
           if (s + x <= B) {
               s += x;
           }else s -= y;
           ans += s;
       }
       cout << ans << "\n";
    }
    
    return 0;
}