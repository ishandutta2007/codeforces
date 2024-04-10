#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector <string> s(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'R')
          sum++;
      }
    }
    vector <pair <int, int> > e;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < m; j++) {
          e.push_back({i, j});
        }
      } else {
        for (int j = m - 1; j >= 0; j--) {
          e.push_back({i, j});
        }
      }
    }
    vector <int> f;
    for (int i = 0; i < k; i++) {
      f.push_back(sum / k + (i < sum % k));
    }
    int ptr = 0;
    int tot = 0;
    vector <vector <int> > ans(n, vector <int> (m));
    for (auto c : e) {
      ans[c.first][c.second] = ptr;
      tot += s[c.first][c.second] == 'R';
      if (f[ptr] == tot && ptr < k - 1) {
        tot = 0;
        ptr++;
      }
    }
    auto ind = [&] (int x) {
      if (x < 26) return char(x + 'a');
      else if (x < 52) return char(x - 26 + 'A');
      else return char(x - 52 + '0');
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << ind(ans[i][j]);
      }
      cout << '\n';
    }
  }
}