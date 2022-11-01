#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char s[N];
int n, _pok, _eat;
vector <int> pok;
vector <int> eat;

bool ok (int x) {
  int at = 0;
  for (int p : pok) {
    if (at >= _eat) {
      return 1;
    }
    if (eat[at] < p) {
      if (p - eat[at] > x) {
        return 0;
      }
      int cur = eat[at];
      int rem = x - (p - eat[at]);
      while (at < _eat and eat[at] < p) ++at;
      if (at >= _eat) return 1;
      while (at < _eat and min(eat[at] - cur, 2 * (eat[at] - p)) <= rem) {
        ++at;
      }
      if (at >= _eat) return 1;
    } else {
      while (at < _eat and eat[at] - p <= x) {
        ++at;
      }
      if (at >= _eat) return 1;
    }
  }
  return at >= _eat;
}

int main() {
  scanf("%d %s", &n, s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'P') pok.push_back(i);
    if (s[i] == '*') eat.push_back(i);
  }
  _pok = pok.size();
  _eat = eat.size();
  int lo = 0, hi = 100 * n;
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}