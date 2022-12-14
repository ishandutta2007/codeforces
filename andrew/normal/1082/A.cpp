#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll q;
    cin >> q;
    while(q--){
        ll n, x, y, d;
        cin >> n >> x >> y >> d;
        if(abs(x - y) % d == 0)cout << abs(x - y) / d << "\n"; else{
            ll ans = 1e18;
            if(abs(y - 1) % d == 0)ans = min(ans, (x + d - 2) / d + (y + d - 2) / d);
            if(abs(n - y) % d == 0)ans = min(ans, (n - x + d - 1) / d + (n - y + d - 1) / d);
            if(ans == 1e18)ans = -1;
            cout << ans << "\n";
        }
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}