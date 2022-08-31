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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <vector <int> > g(n);
    auto add_edge = [&] (int i, int j) {
      if (j < n) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    };
    for (int i = 0; i < n; i++) {
      add_edge(i, n - 1 - i);
      add_edge(i, i + k);
    }
    vector <char> u(n);
    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (!u[i]) {
        int x = i;
        vector <int> q;
        u[x] = 1;
        q.push_back(x);
        map <char, int> cnt;
        for (int i = 0; i < (int) q.size(); i++) {
          int v = q[i];
          cnt[s[v]]++;
          for (int to : g[v]) {
            if (!u[to]) {
              u[to] = true;
              q.push_back(to);
            }
          }
        }
        int mx = 0;
        for (auto c : cnt) mx = max(mx, c.second);
        int s = 0;
        for (auto c : cnt) s += c.second;
        ret += s - mx;
      }
    }
    cout << ret << '\n';
  }
}