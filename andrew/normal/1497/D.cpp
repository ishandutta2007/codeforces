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
const ll M = 2e5;
const int N = 1e7;
const int inf = 1e8;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


void solve(){
    ll n, val;
    cin >> n;

    vector <ll> tag(n + 1), s(n + 1), dp(n + 1);

    for(int i = 1; i <= n; i++)cin >> tag[i];
    for(int i = 1; i <= n; i++)cin >> s[i];

    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j > 0; j--)if(tag[i] != tag[j]){
            val = dp[i];
            dp[i] = max(dp[i], dp[j] + abs(s[i] - s[j]));
            dp[j] = max(dp[j], val + abs(s[i] - s[j]));
        }
    }
    
    cout << *max_element(all(dp)) << "\n";
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