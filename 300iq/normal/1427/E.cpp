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

const ll inf = 1e18;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll x;
  cin >> x;
  while (true) {
    vector<ll> v = {x};
    set<ll> st;
    string plus = " + ";
    string xr = " ^ ";
    vector<string> ans;
    for (int i = 0; v.size() < 90000; ++i) {
      ll x = v[rnd() % v.size()];
      ll y = v[rnd() % v.size()];
      if (x + y < inf && !st.count(x + y))
        st.insert(x + y), v.push_back(x + y),
            ans.push_back(to_string(x) + plus + to_string(y));
      if (x ^ y < inf && !st.count(x ^ y))
        st.insert(x ^ y), v.push_back(x ^ y),
            ans.push_back(to_string(x) + xr + to_string(y));
      auto it = st.lower_bound(x);
      auto it1 = next(it);
      for (int j = 0; j < 2 && it1 != st.end(); ++j, it1 = next(it1)) {
        ll a = *it, b = *it1;
        if (a ^ b < inf && !st.count(a ^ b))
          st.insert(a ^ b), v.push_back(a ^ b),
              ans.push_back(to_string(a) + xr + to_string(b));
        if (a + b < inf && !st.count(a + b))
          st.insert(a + b), v.push_back(a + b),
              ans.push_back(to_string(a) + plus + to_string(b));
      }
    }
    sort(v.begin(), v.end());
    v.push_back(inf);
    int C = 1 << 13;
    vector<char> ex(C);
    int ptr = 0;
    for (int i = 0; i < v.size(); ++i) {
      ll x = v[i];
      if (x < C) ex[x] = true;
      while (ptr < v.size() && v[ptr] - x < C) ++ptr;
      for (int j = i + 1; j < ptr; ++j)
        if ((v[j] ^ v[i]) < C && !ex[v[j] ^ v[i]]) {
          ans.push_back(to_string(v[i]) + xr + to_string(v[j]));
          ex[v[j] ^ v[i]] = true;
        }
    }
    vector<char> ok(C);
    ok[0] = true;
    for (int x = 0; x < C; ++x) {
      if (ok[1]) break;
      if (!ex[x]) continue;
      for (int y = 0; y < C; ++y) {
        if (ok[y] && !ok[x ^ y]) {
          ok[x ^ y] = true, ans.push_back(to_string(x) + xr + to_string(y));
          if (x ^ y == 1) break;
        }
      }
    }
    if (!ok[1]) continue;
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << '\n';
    return 0;
  }
}