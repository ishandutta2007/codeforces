#include <cmath>
#include <functional>
#include <fstream>
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
    int n;
    cin >> n;
    vector <int> a(n);
    vector <vector <int> > p(200);
    vector <vector <int> > f(200);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      p[a[i]].push_back(i);
    }
    for (int x = 0; x < 200; x++) {
      int s= 0;
      for (int i = 0; i < n; i++) {
        if (a[i] == x)  s++;
        f[x].push_back(s);
      }
    }
    int ans = 0;
    auto best = [&] (int l, int r) {
      int ret = 0;
      for (int m = 0; m < 200; m++) {
        ret = max(ret, f[m][r] - (l ? f[m][l - 1] : 0));
      }
      return ret;
    };
    for (int x = 0; x < 200; x++) {
      ans = max(ans, (int) p[x].size());
      for (int i = 0; i < (int) p[x].size() && (int) p[x].size() - 1 - i > i; i++) {
        int l = p[x][i] + 1, r = p[x][(int) p[x].size() - 1 - i] - 1;
        ans = max(ans, 2 * (i + 1) + best(l, r));
      }
    }
    cout << ans << '\n';
  }
}