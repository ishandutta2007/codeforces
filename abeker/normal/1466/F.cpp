#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;

int N, M;
int dad[MAXN], rnk[MAXN];
bool loop[MAXN];
vector <int> ans;

int find(int x) {
  return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y, int z) {
  int dx = find(x);
  int dy = find(y);
  if (dx != dy) {
    if (loop[dx] && loop[dy])
      return;
    if (rnk[dx] > rnk[dy])
      swap(dx, dy);
    dad[dx] = dy;
    rnk[dy] += rnk[dx] == rnk[dy];
    loop[dy] |= loop[dx];
    ans.push_back(z);
    return;
  }
  if (x == y && !loop[dx]) {
    loop[dx] = true;
    ans.push_back(z);
  }
}

int main() {
  scanf("%d%d", &N, &M);
  iota(dad + 1, dad + M + 1, 1);
  for (int i = 1; i <= N; i++) {
    int k;
    scanf("%d", &k);
    vector <int> x(k);
    for (auto &it : x)
      scanf("%d", &it);
    join(x[0], x[1 % k], i);
  }
  int ways = 1;
  for (int i = 0; i < ans.size(); i++)
    ways = 2 * ways % MOD;
  printf("%d %d\n", ways, ans.size());
  for (auto it : ans)
    printf("%d ", it);
  puts("");
  return 0;
}