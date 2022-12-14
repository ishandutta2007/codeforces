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

ll dp[2][5001][5001], value[5001], c[5001], d[5001];

vector <ll> v[MAXN];

ll n, b, ans = 0;
void dfs(ll x){

    for(int i = 0; i <= n; i++)dp[0][x][i] = dp[1][x][i] = 1e18;

    dp[0][x][0] = 0;

    if(v[x].empty()){
        value[x] = 1;
        dp[0][x][1] = c[x];
        dp[1][x][1] = d[x];
        return;
    }


    for(auto &to : v[x]){
        dfs(to);
        for(int i = value[x]; i >= 0; i--)
            for(int j = 1; j <= value[to]; j++){
                dp[0][x][i + j] = min(dp[0][x][i + j], dp[0][x][i] + dp[0][to][j]);

                dp[1][x][i + j] = min(dp[1][x][i + j], dp[1][x][i] + dp[1][to][j]);
                dp[1][x][i + j] = min(dp[1][x][i + j], dp[1][x][i] + dp[0][to][j]);
                dp[1][x][i + j] = min(dp[1][x][i + j], dp[0][x][i] + dp[1][to][j]);
        }
        value[x] += value[to];
    }

    value[x]++;

    for(int i = value[x]; i >= 0; i--){
        dp[0][x][i + 1] = min(dp[0][x][i + 1], dp[0][x][i] + c[x]);

        dp[1][x][i + 1] = dp[1][x][i] + d[x];
        dp[1][x][i + 1] = min(dp[1][x][i + 1], dp[0][x][i] + d[x]);
    }
    dp[1][x][0] = 1e18;

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> b;

    for(int i = 1; i <= n; i++){
        cin >> c[i] >> d[i];
        d[i] = c[i] - d[i];
        ll x;
        if(i != 1){
            cin >> x;
            v[x].p_b(i);
        }
    }

    dfs(1ll);

    for(int i = n; i >= 0; i--)if(min(dp[0][1][i], dp[1][1][i]) <= b){
            vout(i);
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}