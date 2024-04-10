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

struct triple {
  int who;
  int a, b;
  string op;
};

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <triple> e;
  string l = "", r = "";
  map <string, int> id;
  int sz = 0;
  auto who = [&] (string s) {
    if (id.count(s)) {
      return id[s];
    } else {
      id[s] = sz++;
      return id[s];
    }
  };
  for (int i = 0; i < n; i++) {
    string l;
    cin >> l;
    string s;
    cin >> s;
    string t;
    cin >> t;
    if ('0' <= t[0] && t[0] <= '1') {
      e.push_back({who(l), -1, -1, t});
    } else {
      string a = t;
      string b = "";
      cin >> s >> b;
      e.push_back({who(l), who(a), who(b), s});
    }
  }
  for (int i = 0; i < m; i++) {
    vector <pair <int, int> > ret;
    for (int c = 0; c < 2; c++) {
      vector <int> val(n + 1);
      val[who("?")] = c;
      int sum = 0;
      for (auto &t : e) {
        if (t.a == -1) {
          val[t.who] = (t.op[i] - '0');
        } else {
          if (t.op == "XOR")
            val[t.who] = val[t.a] ^ val[t.b];
          else if (t.op == "AND")
            val[t.who] = val[t.a] & val[t.b];
          else
            val[t.who] = val[t.a] | val[t.b];
        }
        sum += val[t.who];
      }
      ret.push_back({sum, c});
    }
    int mn = min(ret[0].first, ret[1].first);
    int mx = max(ret[0].first, ret[1].first);
    if (ret[0].first == mn) {
      l += '0';
    } else {
      l += '1';
    }
    if (ret[0].first == mx) {
      r += '0';
    } else {
      r += '1';
    }
  }
  cout << l << endl;
  cout << r << endl;
}