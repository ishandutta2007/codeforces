#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int dp[3][505][505];
int mod = 1000000007;
int n, m;
string s[505];
int a[505][505];
vector < pii > g[1555];

void add(int &val, int cur){
    val += cur;
    if( val >= mod) val -= mod;
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = g[i + j].size();
            g[i + j].pb( mp(i, j) );
        }
    }
    
    int len = n + m - 2;
    int ff;
    int ss;
    int cur = 0;
    if( len & 1){
        ff = len/2;
        ss = ff + 1;
        for(int i = 0; i < g[ff].size(); i++){
            int x1 = g[ff][i].f;
            int y1 = g[ff][i].s;
            for(int j = 0; j < g[ss].size(); j++){
                int x2 = g[ss][j].f;
                int y2 = g[ss][j].s;
                if(s[x1][y1] != s[x2][y2]) continue;
                if( x1 == x2 && y1 == y2 - 1) dp[0][i][j] = 1;
                if( x1 == x2 - 1 && y1 == y2) dp[0][i][j] = 1;
            }
        }
        ss++;
        ff--;
    }
    else {
        ff = len/2;
        ss = ff + 1;
        for(int i = 0; i < g[ff].size(); i++){
            dp[0][i][i] = 1;
        }
        ff--;
    }
    while( ff >= 0){
        int  nxt = cur ^ 1;
        for(int i = 0; i < 501; i++)
            for(int j = 0; j < 501; j++)
                dp[nxt][i][j] = dp[cur][i][j];
        memset(dp[cur], 0, sizeof dp[cur]);
        for(int i = 0; i < g[ff].size(); i++){
            int x1 = g[ff][i].f;
            int y1 = g[ff][i].s;
            for(int j = 0; j < g[ss].size(); j++){
                int x2 = g[ss][j].f;
                int y2 = g[ss][j].s;
                if(s[x1][y1] != s[x2][y2]) continue;
                if(x1 + 1 < n){
                    if(x2 > 0)add(dp[cur][i][j], dp[nxt][a[x1 + 1][y1]][a[x2 - 1][y2]]);
                    if( y2 > 0)add(dp[cur][i][j], dp[nxt][a[x1 + 1][y1]][a[x2][y2-1]]);
                }
                if( y1 + 1 < m){
                    if(x2 > 0) add(dp[cur][i][j], dp[nxt][a[x1][y1+1]][a[x2 - 1][y2]]);
                    if( y2 > 0) add(dp[cur][i][j], dp[nxt][a[x1][y1+1]][a[x2][y2-1]]);
                }
            }
        }
        ff--;
        ss++;
    }
    cout << dp[cur][a[0][0]][a[n-1][m-1]] << endl;








    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}