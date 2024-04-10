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

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  map <string, vector <int> > mda;
  int n, k;
  cin >> n >> k;
  for (int i= 0;i < n; i++) {
    string s;
    cin >> s;
    int cost;
    cin >> cost;
    mda[s].push_back(cost);
  }
  for (auto &c : mda) {
    sort(c.second.rbegin(), c.second.rend());
  }
  ll ans = 0;
  ll odd = 0;
  for (auto &c : mda) {
    string t = c.first;
    reverse(t.begin(), t.end());
    if (t < c.first) {
      ll best = 0;
      ll s= 0;
      for (int i = 0; i < (int) c.second.size() && i < mda[t].size(); i++) {
        s += c.second[i];
        s += mda[t][i];
        best = max(best, s);
      }
      ans += best;
    } else if (t == c.first) {
      ll s= 0;
      int mda = 0;
      ll last = 0;
      ll fir = -1e18;
      for (int i = 0; i < (int) c.second.size(); i++) {
        if (c.second[i] > 0) {
          last = c.second[i];
          s += c.second[i];
          mda++;
        } else {
          fir = c.second[i];
          break;
        }
      }
      if (mda % 2 == 0) {
        ans += s;
      } else {
        ll me = max(s - last, s + fir);
        ll delta_odd = s - me;
        ans += me;
        odd = max(odd, delta_odd);
      }
    }
  }
  cout << ans + odd << endl;
}