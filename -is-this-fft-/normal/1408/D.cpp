#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define x first
#define y second

const int MAX_N = 2e3 + 5;

pair<int, int> rob [MAX_N];
pair<int, int> ts [MAX_N];

bool tscmp (pair<int, int> p, pair<int, int> q) {
  if (p.first != q.first) {
    return p.first > q.first;
  }
  return p.second > q.second;
}

typedef long long ll;

ll cur [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> rob[i].x >> rob[i].y;
  }

  for (int i = 0; i < m; i++) {
    cin >> ts[i].x >> ts[i].y;
  }

  sort(ts, ts + m, tscmp);

  int mxy = -1;
  vector<pair<int, int>> lights;
  for (int i = 0; i < m; i++) {
    if (ts[i].y > mxy) {
      lights.push_back(ts[i]);
      mxy = ts[i].y;
    }
  }
  m = lights.size();

  set<pair<int, int>> ys;
  vector<pair<int, pair<int, int>>> events;
  for (int i = 0; i < n; i++) {
    int cury = 0;
    for (int j = 0; j < m; j++) {
      if (rob[i].x <= lights[j].x) {
        events.push_back(make_pair(lights[j].x - rob[i].x + 1, make_pair(i, cury)));
        cury = max(0, lights[j].y - rob[i].y + 1);
      } else {
        break;
      }
    }
    cur[i] = cury;
    ys.insert(make_pair(cur[i], i));
  }

  sort(events.begin(), events.end());
  int ans = ys.rbegin()->first;
  for (auto pr : events) {
    int idx = pr.second.first;
    ys.erase(make_pair(cur[idx], idx));
    cur[idx] = pr.second.second;
    ys.insert(make_pair(cur[idx], idx));
    ans = min(ans, ys.rbegin()->first + pr.first);
  }
  cout << ans << endl;
}