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

        vector <ll> a(n);
        for (auto &i : a) cin >> i;
        cout << min_element(all(a)) - a.begin() + 1 << " " << max_element(all(a)) - a.begin() + 1 << "\n";
    }

    
    return 0;
}