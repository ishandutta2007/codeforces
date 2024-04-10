#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define l first
#define r second

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<pair<int, int>> segs (n);
  vector<pair<int, pair<int, int>>> events; // <time, <type, id>>
  for (int i = 0; i < n; i++) {
    cin >> segs[i].l >> segs[i].r;
    events.push_back({segs[i].l, {0, i}});
    events.push_back({segs[i].r, {1, i}});
  }

  vector<int> added (n, 0);

  sort(events.begin(), events.end());
  int last = -1e9 - 10;
  set<int> cur;
  int gapc = 0;
  int isolc = 0;
  int all_sep = 1;
  for (int i = 0; i < (int) events.size(); i++) {
    auto e = events[i];
    int time = e.l;
    int type = e.r.l;
    int idx = e.r.r;

    if ((int) cur.size() > 1) {
      all_sep = 0;
    }
    
    if (last < time && (int) cur.size() == 1) {
      added[*cur.begin()]++;
    } else if (last < time && cur.empty()) {
      gapc++;
    }

    int isol = 0;
    if (i == 0 || events[i - 1].l != time) {
      if (i == (int) events.size() - 1 || events[i + 1].l != time) {
        isol = 1;
      }
    }
    isolc++;

    if (type == 0) {
      if (isol && cur.empty()) {
        added[idx]--;
      }
      cur.insert(idx);
    }
    if (type == 1) {
      cur.erase(idx);
      if (isol && cur.empty()) {
        added[idx]--;
      }
    }

    last = time;
  }

  if (all_sep && isolc == 2 * n) {
    cout << n - 1 << '\n';
    return;
  }
  
  int ans = gapc;
  for (int i = 0; i < n; i++) {
    if (added[i] < 0) added[i] = 0;
    ans = max(ans, gapc + added[i]);
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}