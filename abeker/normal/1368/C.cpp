#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int N;
vector <pii> ans;

void add(int x, int y) {
  ans.push_back({x, y});
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N + 1; i++) {
    add(i, i + 1);
    add(i + 1, i);
    add(i, i);
  }
  add(N + 2, N + 2);
  printf("%d\n", ans.size());
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);
  return 0;
}