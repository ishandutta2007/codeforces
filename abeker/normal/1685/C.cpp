#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N;
char s[MAXN];
int pref[MAXN];

void load() {
  scanf("%d%s", &N, s + 1);
  N *= 2;
}

void update_max(int &best, int cand) {
  if (pref[cand] > pref[best])
    best = cand;
}

vector <pii> solve() {
  for (int i = 1; i <= N; i++)
    pref[i] = pref[i - 1] + (s[i] == '(' ? 1 : -1);
  assert(!pref[N]);
  int lo = N + 1, hi = 0;
  for (int i = 1; i <= N; i++)
    if (pref[i] < 0) {
      lo = min(lo, i);
      hi = max(hi, i);
    }
  if (!hi)
    return {};
  vector <pii> sorted;
  for (int i = 0; i <= N; i++)
    sorted.push_back({pref[i], i});
  sort(sorted.begin(), sorted.end());
  int mid = max_element(pref + lo, pref + hi) - pref;
  vector <pii> two = {{lo, mid}, {mid, hi + 1}};
  int max_lo = lo, max_hi = hi;
  vector <bool> bio(N + 1);
  for (auto it : sorted) {
    bio[it.second] = true;
    while (lo > 0 && bio[lo - 1])
      update_max(max_lo, --lo);
    while (hi < N && bio[hi + 1])
      update_max(max_hi, ++hi);
    if (it.first >= pref[mid] && pref[max_lo] + pref[max_hi] >= it.first) 
      return {{max_lo + 1, max_hi}};
  }
  return two;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    vector <pii> ans = solve();
    printf("%d\n", ans.size());
    for (auto it : ans)
      printf("%d %d\n", it.first, it.second);
  }
  return 0;
}