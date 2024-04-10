#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXL = 110;
const int MAXN = 9;

int N, L;
vector <vector <array <int, 2>>> pos;
pii dad[MAXL][1 << MAXN];
int dp[MAXL][1 << MAXN];
string upd;

void load() {
  scanf("%d", &N);
  vector <string> inp;
  for (int i = 0; i < N; i++) {
    char buff[105];
    scanf("%s", buff);
    inp.push_back(buff);
    inp.back() = ' ' + inp.back();
  }
  L = 0;
  upd = "";
  pos.resize(N - 1);
  for (int i = 0; i < N - 1; i++)
    pos[i].clear();
  for (int i = 0; i < inp.back().size(); i++) {
    vector <array <int, 2>> to_add;
    for (int j = 0; j < N - 1; j++) {
      vector <int> occ;
      for (int k = 0; k < inp[j].size(); k++)
        if (inp[j][k] == inp.back()[i])
          occ.push_back(k);
      assert(occ.size() <= 2);
      if (occ.empty())
        break;
      to_add.push_back({occ[0], occ[1 % occ.size()]});
    }
    if (to_add.size() < N - 1)
      continue;
    upd += inp.back()[i];
    for (int j = 0; j < N - 1; j++)
      pos[j].push_back(to_add[j]);
    L++;
  }
}

int rec(int x, int mask) {
  int &ref = dp[x][mask];
  if (ref != -1)
    return ref;
  ref = 0;
  pii &best = dad[x][mask];
  best = {-1, -1};
  for (int i = x + 1; i < L; i++) {
    int nxt = 0;
    for (int j = 0; j < N - 1; j++)
      if (pos[j][i][1] <= pos[j][x][mask >> j & 1]) {
        nxt = -1;
        break;
      }
      else if (pos[j][i][0] <= pos[j][x][mask >> j & 1])
        nxt |= 1 << j;
    if (nxt == -1)
      continue;
    int tmp = rec(i, nxt);
    if (tmp > ref) {
      ref = tmp;
      best = {i, nxt};
    }
  } 
  return ++ref;
}

void solve() {
  memset(dp, -1, sizeof dp);
  printf("%d\n", rec(0, 0) - 1);
  for (pii curr = dad[0][0]; curr != pii(-1, -1); curr = dad[curr.first][curr.second])
    printf("%c", upd[curr.first]);
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