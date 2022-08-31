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

const int N = 1e5 + 7;

vector <int> kek[N];
vector <pair <int, int> > f[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int free = 0; 
  multiset <int> a, b;
  ll sa = 0;
  auto add = [&] (int x) {
    sa += x;
    a.insert(x);
  };
  auto del = [&] (int x) {
    if (a.find(x) != a.end()) {
      sa -= x;
      a.erase(a.find(x));
    } else {
      b.erase(b.find(x));
    }
  };
  auto get = [&] (int k) {
    while (a.size() > k) {
      sa -= *a.rbegin();
      b.insert(*a.rbegin());
      a.erase(--a.end());
    }
    while (a.size() < k) {
      sa += *b.begin();
      a.insert(*b.begin());
      b.erase(b.begin());
    }
    while (a.size() && b.size() && *a.rbegin() > *b.begin()) {
      ll x= *a.rbegin();
      ll y = *b.begin();
      a.erase(a.find(x));
      b.erase(b.find(y));
      sa -= x;
      sa += y;
      a.insert(y);
      b.insert(x);
    }
    return sa;
  };
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      free++;
    } else {
      a--;
      add(b);
      kek[a].push_back(b);
    }
  }
  for (int i = 0; i < N; i++) {
    sort(kek[i].rbegin(), kek[i].rend());
    while (!kek[i].empty()) {
      f[(int) kek[i].size()].push_back({kek[i].back(), i});
      kek[i].pop_back();
    }
  }
  ll ans = 1e18;
  ll bad = 0;
  int have = free;
  for (int i = n; i >= 0; i--) {
    for (auto c : f[i]) {
      del(c.first);
      bad += c.first;
      have++;
    }
    int need_gays = max(0, i - have);
    if (a.size() + b.size() >= need_gays) {
      ans = min(ans, get(need_gays) + bad);
    }
  }
  cout << ans << endl;
}