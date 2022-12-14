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
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    ll n, m;
    cin >> n >> m;
    if(n > m){
        fout(0);
    }
    ll mask = 0;
    for(ll i = 40; i >= 0; i--){
        if(!(pw(i) & n)){
            mask |= pw(i);
        }
    }
    ll ans = 0;

    for(ll i = 40; i >= 0; i--){
        if(!(pw(i) & n)){
            mask ^= pw(i);
        }
        if((mask | ans | n) <= m){
            if(!(pw(i) & n)){
                ans |= pw(i);
            }   
        }   
    }

    cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    //t = 1;

    while(t--){
        solve();
    }    

    return 0;
}