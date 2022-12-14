#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;



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
        ll n, k;
        cin >> n >> k;
        bool good = 0;
        map <ll, ll> mp;
        while (n--) {
            ll x;
            cin >> x;
            if (mp[x - k] || mp[x + k]) {
                good = 1;
            }
            mp[x] = 1;
        }
        if (good) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }

    
    return 0;
}