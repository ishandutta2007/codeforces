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
int mod = 1000000009;
int n, h;
int dp[2][31][31][31][2];
int nxt[35];

void add(int &v, int r){
    v += r;
    if(v >= mod) v-= mod;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n >> h;
//  cerr << -1 << endl;
    int prev = 0;
    int cur = 1;
    for(int i = 0; i <= h; i++){
        for(int j = i; j <= h; j++)
            for(int k = j; k <= h; k++)
                for(int t = 0; t < 2; t++)
                    if(t || i < h) dp[prev][k][j][i][t] = 1;
    }
    for(int i = 0; i <= h+ 1; i++)
        nxt[i] = min(i+1, h);

    for(int pos = n-1; pos >= 0; pos--){
        
        for(int i = 0; i <= h; i++)
            for(int j = i; j <= h; j++)
                for(int k = j; k <= h; k++){    
                    add(dp[cur][k][j][i][1], dp[prev][nxt[k]][nxt[j]][nxt[i]][1]);
                    add(dp[cur][k][j][i][1], dp[prev][nxt[k]][nxt[j]][1][i<h]); 
                    add(dp[cur][k][j][i][1], dp[prev][nxt[k]][nxt[i]][1][j<h]);
                    add(dp[cur][k][j][i][1], dp[prev][nxt[j]][nxt[i]][1][k<h]);
                    if(i < h){
                        add(dp[cur][k][j][i][0], dp[prev][nxt[k]][nxt[j]][nxt[i]][0]);
                        add(dp[cur][k][j][i][0], dp[prev][h][nxt[k]][nxt[j]][i<h]); 
                        add(dp[cur][k][j][i][0], dp[prev][h][nxt[k]][nxt[i]][j<h]);
                        add(dp[cur][k][j][i][0], dp[prev][h][nxt[j]][nxt[i]][k<h]);
                    }
                }
        swap(prev, cur);
        for(int i = 0; i <= h; i++)
            for(int j = i; j <= h; j++)
                for(int k = j; k <= h; k++){    
                    dp[cur][k][j][i][1]=0; 
                    dp[cur][k][j][i][0]=0; 
                }
        
            
    }
    cout << dp[prev][0][0][0][1] << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}