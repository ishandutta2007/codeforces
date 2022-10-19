#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
int freq[MAXN];
int a[MAXN], b[MAXN];
vector <int> pos[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

void solve() {
  for (int i = 1; i <= N; i++)
    pos[i].clear();
  for (int i = 1; i <= N; i++)
    pos[a[i]].push_back(i);
  vector <int> vals;
  for (int i = 1; i <= N; i++)
    if (!pos[i].empty()) {
      freq[i] = pos[i].size();
      vals.push_back(i);
    }
  sort(vals.begin(), vals.end(), [&](int x, int y) { return freq[x] < freq[y]; });
  for (int i = 1; i < vals.size(); i++)
    for (auto it : pos[vals[i - 1]])
      b[it] = vals[i];
  for (int i = 0; i < vals.size(); i++)
    for (int j = i ? freq[vals[i - 1]] : 0; j < freq[vals[i]]; j++) {
      b[pos[vals.back()].back()] = vals[i];
      pos[vals.back()].pop_back();
    }
  for (int i = 1; i <= N; i++)
    printf("%d ", b[i]);
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