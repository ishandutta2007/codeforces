#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;
const int LOG = 30;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

ll solve() {
  vector <vector <int>> curr(1);
  curr[0].resize(N);
  iota(curr[0].begin(), curr[0].end(), 0);
  ll mini = 0;
  int best = 0;
  for (int i = LOG - 1; i >= 0; i--) {
    vector <ll> sum(2);
    vector <vector <int>> nxt;
    for (auto it : curr) {
      vector <int> zero, one;
      ll inv_zero = 0, inv_one = 0;
      for (auto elem : it)
        if (a[elem] >> i & 1) { 
          one.push_back(elem);
          inv_one += zero.size();
        }
        else {
          zero.push_back(elem);
          inv_zero += one.size();
        }
      if (!one.empty())
        nxt.push_back(one);
      if (!zero.empty())
        nxt.push_back(zero);
      sum[0] += inv_zero;
      sum[1] += inv_one;
    }
    int opt = min_element(sum.begin(), sum.end()) - sum.begin();
    mini += sum[opt];
    best |= opt << i;
    curr = nxt;
  }
  printf("%lld %d\n", mini, best);
}

int main() {
  load();
  solve();
  return 0;
}