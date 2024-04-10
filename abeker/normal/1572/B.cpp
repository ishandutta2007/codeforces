#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

void solve() {
  int st = -1;
  queue <pii> blocks;
  for (int i = 0; i < N; i++) {
    if (!a[i])
      continue;
    if (!i || !a[i - 1])
      st = i;
    if (i == N - 1 || !a[i + 1])
      blocks.push({st, i});
  }
  vector <int> ans;
  auto make_move = [&](int x) {
    ans.push_back(x + 1);
  };
  while (!blocks.empty()) {
    pii curr = blocks.front();
    blocks.pop();
    if ((curr.second - curr.first) % 2) {
      if (curr.first)
        for (int i = curr.first - 1; i < curr.second; i += 2)
          make_move(i);
      else if (curr.second < N - 1) 
        for (int i = curr.second - 1; i >= curr.first; i -= 2)
          make_move(i);
      else {
        puts("NO");
        return;
      }
    }
    else {
      if (blocks.empty()) {
        puts("NO");
        return;
      }
      pii &nxt = blocks.front();
      for (int i = curr.second; i < nxt.first - 2; i += 2)
        make_move(i);
      if ((nxt.first - curr.second) % 2) 
        nxt.first = curr.first;
      else {
        for (int i = nxt.first - 2; i >= curr.first; i -= 2)
          make_move(i);
        if (++nxt.first > nxt.second)
          blocks.pop();
      }
    }
  }
  assert(ans.size() <= N);
  for (auto it : ans)
    a[it - 1] = a[it] = a[it + 1] = a[it - 1] ^ a[it] ^ a[it + 1];
  assert(!accumulate(a, a + N, 0));
  printf("YES\n%d\n", ans.size());
  for (auto it : ans)
    printf("%d ", it);
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