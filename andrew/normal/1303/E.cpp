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
const ll MAXN = 1123456;
const ll inf = 1e8;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[410][410];

void u(ll &a, ll b){
    a = max(a, b);
}

void solve(){
    string s, t;
    cin >> s >> t;
    if(sz(t) > sz(s))fout("NO");
    ll n = sz(s);
    for(int cnt = 1; cnt <= sz(t); cnt++){
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= cnt; j++)dp[i][j] = -1;

        dp[0][0] = 0;

        ll cnta = sz(t) - cnt;

        for(int i = 1; i <= n; i++){
            for(int old = 0; old <= cnt; old++)if(dp[i - 1][old] != -1){
                int r = dp[i - 1][old];
                u(dp[i][old], r);
                if(old < cnt && s[i - 1] == t[old])u(dp[i][old + 1], r);
                if(r < cnta && s[i - 1] == t[r + cnt])u(dp[i][old], r + 1);
            }
        }
        if(dp[n][cnt] == cnta)fout("YES");
    }

    fout("NO");

}


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        solve();
    }


    return 0;
}