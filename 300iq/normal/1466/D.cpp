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
    vector <int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    vector <int> deg(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += w[i];
    vector <int> ders;
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      deg[a]++, deg[b]++;
    }
    for (int i = 0; i < n; i++) {
      for (int x = 0; x < deg[i] - 1; x++) {
        ders.push_back(w[i]);
      }
    }
    sort(ders.rbegin(), ders.rend());
    for (int k = 1; k < n; k++) {
      cout << sum << ' ';
      if (k - 1 < (int) ders.size())
        sum += ders[k - 1];
    }
    cout << '\n';
  }
}