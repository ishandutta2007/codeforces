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
    for (int i= 0; i < n; i++) {
      cin >> a[i];
    }
    int me = a[0];
    int groups = n;
    map <int, int> cnt;
    for (int i = 0; i < n; i++) cnt[a[i]] += 2;
    set <pair <int, int> > q;
    bool bad = false;
    for (auto c : cnt) {
      q.insert({c.second, c.first});
      if (c.second > n + 1) {
        bad = true;
      }
    }
    if (bad) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1]) {
        q.erase({cnt[a[i]], a[i]});
        q.erase({cnt[a[i - 1]], a[i - 1]});
        cnt[a[i]]--, cnt[a[i - 1]]--;
        q.insert({cnt[a[i]], a[i]});
        q.insert({cnt[a[i - 1]], a[i -1]});
        if (q.rbegin()->first <= groups) {
          groups--;
        } else {
          q.erase({cnt[a[i]], a[i]});
          q.erase({cnt[a[i - 1]], a[i - 1]});
          cnt[a[i]]++, cnt[a[i - 1]]++;
          q.insert({cnt[a[i]], a[i]});
          q.insert({cnt[a[i - 1]], a[i -1]});
        }
      }
    }
    cout << groups - 1 << '\n';
  }
}