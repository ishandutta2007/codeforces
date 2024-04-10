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
  int n, m, k;
  cin >> n >> m >> k;
  vector <int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  sort(f.begin(), f.end());
  vector <int> s(m);
  vector <int> ord;
  for (int i = 0; i < m; i++) {
    cin >> s[i];
    ord.push_back(i);
  }
  sort(ord.begin(), ord.end(), [&] (int a, int b) {
    return s[a] > s[b];
  });
  sort(s.begin(), s.end());
  auto check = [&] (int x) {
    vector <int> ok;
    for (int i = m - 1; i > m - 1 - x; i--) {
      ok.push_back(s[i]);
    }
    reverse(ok.begin(), ok.end());
    vector <int> mda(ok.size() + f.size());
    merge(ok.begin(), ok.end(),f.begin(), f.end(), mda.begin());
    for (int i = 0; i < (int) mda.size(); i += k) {
      if (mda[i] < i / k) return false;
    }
    return true;
  };
  if (!check(0)) {
    cout << -1 << '\n';
    return 0;
  }
  int vl = 0, vr = m + 1;
  while (vl < vr - 1) {
    int mid = (vl + vr) / 2;
    if (check(mid)) vl = mid;
    else vr = mid;
  }
  cout << vl << endl;
  for (int i = 0; i < vl; i++) cout << ord[i] + 1 << ' ';
  cout << '\n';
}