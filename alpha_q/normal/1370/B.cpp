#include <bits/stdc++.h>

using namespace std;

const int N = 6969;

int t, n, a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector <int> od, ev;
    for (int i = 1; i <= n + n; ++i) {
      scanf("%d", a + i);
      if (a[i] & 1) od.emplace_back(i);
      else ev.emplace_back(i);
    }
    if (od.size() & 1) {
      od.pop_back(), ev.pop_back();
    } else {
      if (ev.size() > 1) ev.pop_back(), ev.pop_back();
      else od.pop_back(), od.pop_back();
    }
    for (int i = 0; i < od.size(); i += 2) printf("%d %d\n", od[i], od[i + 1]);
    for (int i = 0; i < ev.size(); i += 2) printf("%d %d\n", ev[i], ev[i + 1]);
  }
  return 0;
}