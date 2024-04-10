#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = 998244353ll;
ll const MAXN = (ll)1e3 + 10;

ll bl[MAXN];
ll dp[MAXN][MAXN][2];

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    str s;
    getline(cin, s);
    for(int i = 0;i<n;i++){
        getline(cin, s);
        for(int j = 0; j < m; j++){
            if(s[j] == '#')bl[j] ++;
        }
    }
    //for(int i = 0;i < m;i++)cerr << bl[i] << " ";
    //cerr << endl;
    dp[0][0][0] = bl[0];
    dp[0][0][1] = n - bl[0];

    ll mw, mb;

    for(int i = 1; i < m; i++){
        for(int j = 0 ; j < min(b,i+1ll); j++){
            if(j == 0){
                dp[i][j][0] = 100000000;
                dp[i][j][1] = 100000000;
                for(int k = a - 1; k < min(min(m, b), (ll) i); k++){
                    dp[i][j][0] = min(dp[i][j][0], dp[i-1][k][1]);
                    dp[i][j][1] = min(dp[i][j][1], dp[i-1][k][0]);
                }
                dp[i][j][0] += bl[i];
                dp[i][j][1] += (n - bl[i]);
            } else {
                dp[i][j][0] = dp[i-1][j-1][0] + bl[i];
                dp[i][j][1] = dp[i-1][j-1][1] + n - bl[i];
            }
        }
    }
    /*for(int i = 0;i<m;i++){
        for(int j = 0; j <= i;j++)cerr << dp[i][j][0] << " ";
        cerr << endl;
    }

    for(int i = 0;i<m;i++){
        for(int j = 0; j <= i;j++)cerr << dp[i][j][1] << " ";
        cerr << endl;
    }*/

    ll ans = 100000000;
    for(int i = a - 1; i < min(m,b); i++) ans = min(min(dp[m-1][i][0],dp[m-1][i][1]), ans);
    //for(int i = 0;i<n;i++)
    cout << ans;
    return 0;
}



/*

           _____           ______              ______        _______________           _______________
          /     \         |      \            /      |      /               \         /               \
         /       \        |       \          /       |     /                 \       /                 \
        /   ___   \       |   |\   \        /   /|   |    /    ___________    \     /    ___________    \
       /   /   \   \      |   | \   \      /   / |   |   |    /           \    |   |    /           \    |
      /   /_____\   \     |   |  \   \    /   /  |   |   |   |            |    |   |   |            |    |
     /               \    |   |   \   \  /   /   |   |   |    \___________/    |   |    \___________/    |
    /    _________    \   |   |    \   \/   /    |   |    \                   /     \                   /
   /    /         \    \  |   |     \      /     |   |     \                 /       \                 /
  /____/           \____\ |___|      \____/      |___|      \_______________/         \_______________/

*/