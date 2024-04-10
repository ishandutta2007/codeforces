#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;

class Fenwick  {
  int n;
  vector <int> fen;
public:
  Fenwick(int n) : n(n) {
    fen.resize(n + 1);
  }
  void update(int x) {
    for (x++; x <= n; x += x & -x)
      fen[x]++;
  }
  int get(int x) {
    int res = x;
    for (x++; x; x -= x & -x)
      res -= fen[x];
    return res;
  }
};

int N;
char s[MAXN], t[MAXN];

void load() {
  scanf("%d%s%s", &N, s, t);
}

ll solve() {
  Fenwick counter(N);
  vector <queue <int>> pos(26);
  for (int i = 0; i < N; i++)
    pos[s[i] - 'a'].push(i);
  ll sol = INF, sum = 0;
  for (int i = 0; i < N; i++) {
    auto get_next = [&](int ltr) {
      return pos[ltr].empty() ? -1 : pos[ltr].front();
    };
    int curr = t[i] - 'a';
    for (int j = 0; j < curr; j++) {
      int tmp = get_next(j);
      if (tmp != -1)
        sol = min(sol, sum + counter.get(tmp));
    }
    int tmp = get_next(curr);
    if (tmp == -1)
      break;
    sum += counter.get(tmp);
    counter.update(tmp);
    pos[curr].pop();
  }
  return sol == INF ? -1 : sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%lld\n", solve());
  }
  return 0;
}