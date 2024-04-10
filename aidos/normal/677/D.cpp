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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, m;
vector<int> g[350 * 350];
int a[350][350];
int dis[350][350];
int dp[350];
int p;
void solve(){
  scanf("%d %d %d", &n, &m, &p);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &a[i][j]);
      g[a[i][j]].pb(i * m + j);
      dis[i][j] = inf;
    }
  }
  for(int i = 0; i < g[1].size(); i++){
    int x = g[1][i]/m;
    int y = g[1][i] %m;
    dis[x][y] = x + y;
  }
  for(int i = 2; i <= p; i++){
    if(g[i-1].size() > 300){

      for(int j = 0; j < m; j++)
        dp[j] = -1;
      for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
          if(a[j][k] == i-1) {
            dp[k] = j * m + k;
          }else if(a[j][k] == i){
            for(int t = 0; t <m; t++){
              if(dp[t] == -1) continue;
              int dd = abs(dp[t]/m - j) + abs(dp[t] %m -k) + dis[dp[t]/m][dp[t] % m];
              if(dd < dis[j][k]) dis[j][k] = dd;
            }
          }
        }
      }
      for(int j = 0; j < m; j++)
        dp[j] = -1;
      for(int j = n-1; j>=0; j--){
        for(int k = m-1; k >=0; k--){
          if(a[j][k] == i-1) {
            dp[k] = j * m + k;
          }else if(a[j][k] == i){
            for(int t = m-1; t >= 0; t--){
              if(dp[t] == -1) continue;
              int dd = abs(dp[t]/m - j) + abs(dp[t] %m -k) + dis[dp[t]/m][dp[t] % m];
              if(dd < dis[j][k]) dis[j][k] = dd;
            }
          }
        }
      }
    }
    else {
      for(int j = 0; j < g[i].size(); j++){
        int mini = 1e9;
        int x = g[i][j]/m;
        int y = g[i][j] % m;
        for(int k = 0; k < g[i-1].size(); k++){
          int xx = g[i-1][k]/m;
          int yy = g[i-1][k] % m;
          mini = min(mini, abs(x-xx)+abs(y - yy) + dis[xx][yy]);
        }
        dis[x][y] = mini;
      }
    }
  }
 // cout << -1 << endl;
  for(int i = 0; i < g[p].size(); i++){
    int to = g[p][i];
    cout << dis[to/m][to % m] << endl;;
  }
}




int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}