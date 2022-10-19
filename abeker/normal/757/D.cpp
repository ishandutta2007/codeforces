#include <cstdio>
using namespace std;

const int MAXN = 80;
const int MAXB = 20;
const int MOD = 1000000007;

int N;
char s[MAXN];
int dp[MAXN][1 << MAXB];
int nxt[MAXN];

void load() {
  scanf("%d%s", &N, s);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  else if (x < 0)
    x += MOD;
  return x;
}

int solve() {
  nxt[N] = N;
  for (int i = N - 1; i >= 0; i--)
    nxt[i] = s[i] == '1' ? i : nxt[i + 1];
    
  int sol = 0;
  for (int mx = 1; mx <= MAXB; mx++) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < 1 << mx; j++) 
        dp[i][j] = 0;
      
    for (int i = 0; i <= N; i++)
      for (int j = 0; j < 1 << mx; j++) {
        if (!j)
          dp[i][j] = add(dp[i][j], 1);
        if (!dp[i][j])
          continue;
        int num = 0;
        for (int k = nxt[i]; k < N; k++) {
          num = 2 * num + s[k] - '0';
          if (num > mx)
            break;
          dp[k + 1][j | (1 << num - 1)] = add(dp[k + 1][j | (1 << num - 1)], dp[i][j]);
        }
      }
    
    for (int i = 0; i <= N; i++) 
      sol = add(sol, dp[i][(1 << mx) - 1]);
  }  
  
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}