#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int a[N];
set<int> s;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    s.clear();
    vector<int> freeindices;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (s.count(a[i])) {
        freeindices.push_back(i);
      }
      s.insert(a[i]);
    }
    vector<int> misses;
    for (int i = 1; i <= n; i++) {
      if (!s.count(i)) misses.push_back(i);
    }
    cout << s.size() << '\n';

    assert(misses.size() == freeindices.size());
    if (misses.size() > 1) {
      while (1) {
        bool match = 0;
        for (int i = 0; i < misses.size(); i++) {
          if (misses[i] == freeindices[i]) {
            match = 1;
          }
        }
        if (!match) break;
        else random_shuffle(misses.begin(), misses.end());
      }
      for (int i = 0; i < misses.size(); i++) {
        a[freeindices[i]] = misses[i];
      }
    }
    else if (misses.size() == 1) {
      int f1;
      int f2 = freeindices[0];
      int val = a[f2];
      int missing = misses[0];
      for (int i = 1; i <= n; i++) {
        if (a[i] == val) {
          f1 = i;
          break;
        }
      }
      if (f1 == missing) a[f2] = missing;
      else a[f1] = missing;
    }

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
  }
}