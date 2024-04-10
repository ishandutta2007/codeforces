#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 5;
const ll INF = 1e18;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

vector <ll> dp(int lo, int hi, int dec) {
  if (lo == hi)
    return {0};
  int pos = min_element(a + lo, a + hi) - a;
  vector <ll> lft = dp(lo, pos, a[pos]);
  vector <ll> rig = dp(pos + 1, hi, a[pos]);
  vector <ll> res(hi - lo + 1, INF);
  for (int i = 0; i < lft.size(); i++)
    for (int j = 0; j < rig.size(); j++)
      res[i + j + 1] = min(res[i + j + 1], lft[i] + rig[j]);
  res[0] = 0;
  for (int i = 1; i < res.size(); i++)
    res[i] += a[pos] - dec;
  return res;
}

ll solve() {
  ll sol = INF;
  vector <ll> f = dp(0, N, 0);
  for (int i = 0; i <= N; i++)
    sol = min(sol, f[i] - i);
  return sol + N;
}

int main() {
  load();
  printf("%lld\n", solve());  
  return 0;
}