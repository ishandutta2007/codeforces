#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e7;
const int M = 1e7;
const ll inf = 1e18;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n;
    cin >> n;

    ll ans = inf, sum = 0;

    vector <ll> c(2, inf);

    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        c[i % 2] = min(c[i % 2], x);
        sum += x;
        if(2 <= i){
            ans = min(ans, sum + c[0] * (n - i / 2) + c[1] * (n - (i + 1) / 2));
        }
    }

    cout << ans << "\n";

}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    
    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}