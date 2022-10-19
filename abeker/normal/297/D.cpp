#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

int N, M, K;
char hor[MAXN][MAXN], ver[MAXN][MAXN];
int sol[MAXN][MAXN];

void load() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < N - 1; i++)
    scanf("%s%s", hor[i], ver[i]);
  scanf("%s", hor[N - 1]);
}

void solve() {
  int tot = 2 * N * M - N - M;
  if (K == 1) {
    int cnt = count(hor[N - 1], hor[N - 1] + M - 1, 'E');
    for (int i = 0; i < N - 1; i++)
      cnt += count(hor[i], hor[i] + M - 1, 'E') + count(ver[i], ver[i] + M, 'E');
    if (cnt >= 3 * (tot + 1) / 4) {
      puts("YES");
      for (int i = 0; i < N; i++, puts("")) 
        for (int j = 0; j < M; j++)
          printf("1 ");
    }
    else
      puts("NO");
    return;
  }
  
  if (N <= M) 
    for (int i = 0; i < N; i++) {
      for (int j = 1; j < M; j++)
        sol[i][j] = sol[i][j - 1] ^ (hor[i][j - 1] == 'N');      
      if (!i)
        continue;
      int match = 0;
      for (int j = 0; j < M; j++)
        match += (sol[i][j] == sol[i - 1][j]) ^ (ver[i - 1][j] == 'N'); 
      if (match <= M / 2)
        for (int j = 0; j < M; j++)
          sol[i][j] ^= 1;
    }
  else 
    for (int j = 0; j < M; j++) {
      for (int i = 1; i < N; i++)
        sol[i][j] = sol[i - 1][j] ^ (ver[i - 1][j] == 'N');
      if (!j)
        continue;
      int match = 0;
      for (int i = 0; i < N; i++)
        match += (sol[i][j] == sol[i][j - 1]) ^ (hor[i][j - 1] == 'N');
      if (match <= N / 2)
        for (int i = 0; i < N; i++) 
          sol[i][j] ^= 1;
    }
  
  puts("YES");
  for (int i = 0; i < N; i++, puts(""))
    for (int j = 0; j < M; j++)
      printf("%d ", ++sol[i][j]);
}

int main() {
  load();
  solve();
  return 0;
}