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

int t[M + 10], n;

int last[N + 1];

int last1[N + 1];

pii dp[M + 10][21];

void solve(){
    int k, x, p, f;
    cin >> n >> k;

    vector <int> a(n + 1);

    for(int i = 1; i <= n; i++){
        t[i] = inf;
    }

    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = 1;
        while(x != 1){
            p = last[x];
            f = 0;
            while(x % p == 0){
                f ^= 1;
                x /= p;
            }
            if(f)a[i] *= p;
        }
        last1[a[i]] = 0;
    }

    int l = 1, ans = 1;

    for(int j = 0; j <= k; j++){
        dp[1][j] = {1, -1};
    }

    last1[a[1]] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = {inf, inf};
        }

        for(int j = 0; j <= k; j++){
            if((-dp[i - 1][j].se) <= last1[a[i]]){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], {dp[i - 1][j].fi + 1, -i});
            }else{
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }

        last1[a[i]] = i;
    }

    ans = inf;

    for(int i = 0; i <= k; i++){
        ans = min(ans, dp[n][i].fi);
    }

    cout << ans << "\n";
    
}

/*

1
5 0
18 6 2 4 1

*/

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 2; i <= N; i++)if(!last[i]){
        last[i] = i;
        for(ll j = i * i; j <= N; j += i)last[j] = i;
    }

    int t;
    cin >> t;

    while(t--){
        solve();
    }


    return 0;
}