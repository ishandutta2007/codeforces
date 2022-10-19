#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;

int N;
int perm[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", perm + i);
}

void solve() {
  for (int i = 1; i <= N; i++)
    if ((perm[i] + i) % 2) {
      puts("-1");
      return;
    }
  vector <int> moves;
  auto make_move = [&](int pref) {
    assert(pref % 2);
    reverse(perm + 1, perm + pref + 1);
    moves.push_back(pref);
  };
  auto get_pos = [&](int x) {
    for (int i = 1; i <= N; i++)
      if (perm[i] == x)
        return i;
    assert(false);
  };
  for (int n = N; n > 1; n -= 2) {
    int pos = get_pos(n);
    make_move(pos);
    pos = get_pos(n - 1);
    make_move(pos - 1);
    make_move(pos + 1);
    make_move(3);
    make_move(n);
  }
  assert(moves.size() <= 5 * N / 2);
  for (int i = 1; i <= N; i++)
    assert(perm[i] == i);
  printf("%d\n", moves.size());
  for (auto it : moves)
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