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
    int zo = 0, oo = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') oo++;
      else zo++;
    }
    ll ans = 1e18;
    for (int mod = 0; mod < k; mod++) {
      int z = 0, o = 0;
      for (int i = mod; i < n; i += k) {
        if (s[i] == '1') o++;
        else z++;
      }
      ll here = oo;
      ll delta = 0;
      for (int i = mod; i < n; i += k) {
        if (s[i] == '0') delta++;
        else delta--;
        delta = min(delta, 0ll);
        ans = min(ans, here + delta);
      }
    }
    cout << ans << '\n';
  }
}