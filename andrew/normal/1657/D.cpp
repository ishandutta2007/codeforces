#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

const ll buben = 200;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);                        
        //cin >> t;
    #endif       

    ll n, C;
    cin >> n >> C;

    map <ll, ll> mp;

    for (int i = 0; i < n; i++) {
        ll h, d, c;
        cin >> c >> d >> h;
        mp[c] = max(mp[c], h * d);
    }

    vector <ll> u(C + 1);

    for (auto i : mp) {
        for (int j = i.fi; j <= C; j += i.fi) {
            u[j] = max(u[j], i.se * (j / i.fi));
        }
    }

    int m;
    cin >> m;

    for (int i = 1; i <= C; i++) {
        u[i] = max(u[i], u[i - 1]);
    }

    for (int i = 1; i <= m; i++) {
        ll d, h;
        cin >> d >> h;
        ll x = d * h;
        if (x < u[C]) { 
            ll l = 1, r = C;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (u[mid] <= x) l = mid + 1;
                else r = mid;
            }
            cout << l << "\n";
        }else cout << "-1\n";
    }

    
    return 0;
}