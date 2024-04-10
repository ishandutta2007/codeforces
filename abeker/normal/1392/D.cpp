#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
char s[MAXN];

void load() {
  scanf("%d%s", &N, s);
}

int solve() {
  int last = 0;
  vector <int> blocks;
  for (int i = 1; i < N; i++)
    if (s[i] != s[i - 1]) {
      blocks.push_back(i - last);
      last = i;
    }
  blocks.push_back(N - last);
  if (s[0] == s[N - 1] && blocks.size() > 1) {
    blocks[0] += blocks.back();
    blocks.pop_back();
  }
  int sol = 0;
  for (auto it : blocks)
    sol += it / 3;
  if (blocks.size() == 1 && blocks[0] % 3)
    sol++;
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}