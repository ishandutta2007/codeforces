#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int b[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", b + i);
}

void solve() {
  vector <vector <int>> groups(N + 2);
  for (int i = 1; i <= N; i++)
    groups[b[i]].push_back(i);
  int which = -1;
  vector <int> a;
  vector <int> sum(2);
  vector <int> curr = {0, N + 1};
  while (1) {
    int last = -1;
    for (auto it : curr)
      if (last == -1 && !groups[it].empty())
        last = it;
      else
        a.push_back(it);
    a.push_back(last);
    if (a.size() == 2)
      which = !last;
    else {
      sum[which] += curr.size();
      which ^= 1;
    }
    if (last == -1)
      break;
    curr = groups[last];
  }
  printf("%d\n", sum[0]);
  for (int i = 0; i < N; i++)
    printf("%d ", a[i + 2]);
  puts("");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}