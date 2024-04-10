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
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  for (int i= 0; i < n; i++) cin >> a[i];
  vector <int> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  vector <int> mn(n);
  for (int i = n - 1; i >= 0; i--) {
    mn[i] = a[i];
    if (i + 1 < n) mn[i] = min(mn[i], mn[i + 1]);
  }
  map <int, int> last;
  for (int i = 0; i < n; i++) last[a[i]] = i;
  vector <int> orz;
  vector <int> go(n);
  for (int i = 0; i < n; i++) {
    while (!orz.empty() && a[orz.back()] >= a[i]) {
      orz.pop_back();
    }
    go[i] = (orz.empty() ? -1 : orz.back());
    orz.push_back(i);
  }
  vector <int> st;
  for (int i = 0; i < m; i++) {
    if (!last.count(b[i])) {
      cout << 0 << '\n';
      return 0;
    }
    st.push_back(go[last[b[i]]] + 1);
  }
  for (int i = 0; i < m; i++) {
    int x = st[i];
    if (i == 0 && x != 0) {
      cout << 0 << '\n';
      return 0;
    }
    if (mn[x] != b[i]) {
      cout << 0 << '\n';
      return 0;
    }
  }
  ll ret = 1;
  for (int i = 1; i < (int) st.size(); i++) {
    ret *= (last[b[i]] - st[i] + 1);
    ret %= 998244353;
  }
  cout << ret << endl;
}