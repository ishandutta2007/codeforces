#include <cstdio>
using namespace std;

const int MAXN = 200005;

int N;
int p[MAXN];
bool bio[MAXN];

void dfs(int x) {
  bio[x] = true;
  if (!bio[p[x]])
    dfs(p[x]);
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", p + i);
  int sum = 1;  
  for (int i = 0; i < N; i++) {
    int b;
    scanf("%d", &b);
    sum ^= b;
  }
  
  int cnt = 0;
  for (int i = 1; i <= N; i++)
    if (!bio[i]) {
      dfs(i);
      cnt++;
    }
  if (cnt == 1)
    cnt = 0;
  
  printf("%d\n", sum + cnt);
  
  return 0;
}