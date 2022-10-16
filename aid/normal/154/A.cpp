#include <stdio.h>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cstring>
#include <queue>
#include <list>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  std::ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    vector<pii> b;
    char c1 = a[i][0], c2 = a[i][1];
    bool in = false;
    for (int j = 0; j < s.size(); ++j) {
      if ((s[j] == c1 || s[j] == c2) && !in) {
        b.push_back(s[j] == c1 ? pii(1, 0) : pii(0, 1));
        in = true;
        continue;
      }
      if (s[j] == c1 && in) {
        b.back().first++;
      } else if (s[j] == c2 && in) {
        b.back().second++;
      } else {
        in = false;
      }
    }
    for (int j = 0; j < b.size(); ++j) {
      res += min(b[j].first, b[j].second);
    }
  }
  cout << res;
  return 0;
}