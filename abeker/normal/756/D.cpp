#include <cstdio>
using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

int N;
char s[MAXN];
int dp[MAXN][MAXN];
int choose[MAXN][MAXN];
int last[30];

void load() {
  scanf("%d%s", &N, s + 1);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)   
    x -= MOD;
  else if (x < 0)
    x += MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int solve() {
  choose[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++)
      choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
  }
  
  for (int i = 1; i <= N; i++) {
    int tmp = s[i] - 'a';
    dp[i][1] = !last[tmp];
    for (int j = 2; j <= N; j++)
      dp[i][j] = add(dp[i - 1][j - 1], -dp[last[tmp]][j - 1]);
    for (int j = 1; j <= N; j++)
      dp[i][j] = add(dp[i][j], dp[i - 1][j]);
    last[tmp] = i;
  }
  
  int sol = 0;
  for (int i = 1; i <= N; i++)
    sol = add(sol, mul(choose[N - 1][i - 1], dp[N][i]));
  
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}