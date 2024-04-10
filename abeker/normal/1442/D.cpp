#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int offset = 1 << 12;

int N, K;
int t[offset];
vector <ll> pref[offset];
vector <int> tour[2 * offset];
stack <vector <ll>> dp;

void load() {
  scanf("%d%d", &N, &K);
  memset(t, -1, sizeof t);
  for (int i = 0; i < N; i++) {
    scanf("%d", t + i);
    pref[i].resize(t[i] + 1);
    for (int j = 1; j <= t[i]; j++) {
      scanf("%lld", &pref[i][j]);
      pref[i][j] += pref[i][j - 1];
    }
  }
}

void update(int x, int lo, int hi, int from, int to, int who) {
  if (lo >= to || hi <= from)
    return;
  if (lo >= from && hi <= to) {
    tour[x].push_back(who);
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * x, lo, mid, from, to, who);
  update(2 * x + 1, mid, hi, from, to, who);
}

void update(int from, int to, int who) {
  update(1, 0, offset, from, to, who);
}

ll dfs(int x) {
  for (auto it : tour[x]) {
    vector <ll> nxt = dp.top();
    for (int i = K; i >= t[it]; i--) 
      nxt[i] = max(nxt[i], nxt[i - t[it]] + pref[it].back());
    dp.push(nxt);
  }
  ll res = 0;
  if (x < offset) 
    res = max(dfs(2 * x + 1), dfs(2 * x));
  else 
    for (int i = 0; i <= min(t[x - offset], K); i++)
      res = max(res, pref[x - offset][i] + dp.top()[K - i]);
  for (auto it : tour[x])
    dp.pop();
  return res;
}

ll solve() {
  for (int i = 0; i < N; i++) {
    update(0, i, i);
    update(i + 1, N, i);
  }
  dp.push(vector <ll> (K + 1));
  return dfs(1);
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}