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
        ll n;
        cin >> n;
        map <ll, ll> mp;
        while (n--) {
            ll x;
            cin >> x;
            mp[x] = 1;
        }
        if (!mp[1]) {
            cout << "YES\n";
        }else{
            bool good = 1;
            for (auto i : mp){
                if (mp[i.fi] && mp[i.fi + 1]) good = 0;
            }
            if (good) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    
    return 0;
}