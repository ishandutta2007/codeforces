#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

int better(int a, int b) {
  return ask(a, b) == 1 ? a : b;
}

void solve() {
  int N;
  scanf("%d", &N);
  vector <int> players(1 << N);
  iota(players.begin(), players.end(), 1);
  while (players.size() >= 4) {
    vector <int> nxt;
    for (int i = 0; i < players.size(); i += 4) {
      int tmp = ask(players[i], players[i + 2]);
      if (tmp == 1)
        nxt.push_back(better(players[i], players[i + 3]));
      else if (tmp == 2)
        nxt.push_back(better(players[i + 1], players[i + 2]));
      else
        nxt.push_back(better(players[i + 1], players[i + 3]));
    }
    players = nxt;
  }
  printf("! %d\n", better(players[0], players[1 % players.size()]));
  fflush(stdout);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}