#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int N;
vector <pii> sorted;

void load() {
  scanf("%d", &N);
  sorted.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &sorted[i].first);
    sorted[i].second = i + 1;
  }
}

int ask(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int y;
  scanf("%d", &y);
  return y;
}

void solve() {
  int curr = 0;
  vector <int> clr(N + 1);
  sort(sorted.begin(), sorted.end(), greater <pii> ());
  for (auto it : sorted) {
    if (clr[it.second])
      continue;
    vector <int> adj;
    while (it.first--) {
      int tmp = ask(it.second);
      if (clr[tmp]) {
        clr[it.second] = clr[tmp];
        break;
      }
      adj.push_back(tmp);
    }
    if (!clr[it.second])
      clr[it.second] = ++curr;
    for (auto elem : adj)
      clr[elem] = clr[it.second];
  }
  printf("!");
  for (int i = 1; i <= N; i++)
    printf(" %d", clr[i]);
  puts("");
  fflush(stdout);
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