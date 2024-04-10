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
  int t;
  cin >> t;
  while (t--) {
    int n, T, a, b;
    cin >> n >> T >> a >> b;
    vector <int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector <pair <int, int> > events;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      events.push_back({x, i});
    }
    sort(events.begin(), events.end());
    int ans = 0;
    int can_a = 0, can_b = 0;
    for (int i = 0; i < n; i++) {
      if (!s[i]) can_a++;
      else can_b++;
    }
    int cnt_a = 0, cnt_b = 0;
    for (int i = -1; i < (int) events.size(); i++) {
      int when = (i + 1 >= (int) events.size() ? T : events[i + 1].first - 1);
      if (cnt_a * (ll) a + cnt_b * (ll) b <= when) {
        int solved = i + 1;
        int remain = (when - cnt_a * (ll) a - cnt_b * (ll) b);
        int ok = min(can_a, remain / a);
        solved += ok;
        remain -= ok * a;
        ok = min(can_b, remain / b);
        solved += ok;
        ans = max(ans, solved);
      }
      if (i + 1 < (int) events.size()) {
        if (!s[events[i + 1].second]) cnt_a++, can_a--;
        else cnt_b++, can_b--;
      }
    }
    cout << ans << '\n';
  }
}