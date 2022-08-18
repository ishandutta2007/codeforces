#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Event {
  int type; // -1 - delete, 1 - add
  int time;
  int id;
  int user_id;
};

bool operator< (Event p, Event q) {
  if (p.time != q.time) {
    return p.time < q.time;
  }

  if (p.type != q.type) {
    return p.type < q.type;
  }

  return p.id < q.id;
}

const int MAX_N = 2e4 + 5;

int conn [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, M, T;
  cin >> n >> M >> T;

  set<Event> events;
  for (int i = 0; i < n; i++) {
    string time;
    cin >> time;

    Event e;
    e.time = 0;
    e.time += (int) time[7];
    e.time += 10 * (int) time[6];
    e.time += 60 * (int) time[4];
    e.time += 600 * (int) time[3];
    e.time += 3600 * (int) time[1];
    e.time += 36000 * (int) time[0];

    e.type = 1;
    e.id = i;

    events.insert(e);
  }

  int cur = 0, mx = 0;
  int cnt = 0, last_id = 0;
  vector<int> ans;
  while (!events.empty()) {
    Event e = *events.begin();
    events.erase(events.begin());

    if (e.type == 1) {
      if (cur == M) {
        e.user_id = last_id;
      } else {
        cnt++;
        e.user_id = cnt;
        cur++;
      }

      conn[e.user_id]++;
      last_id = e.user_id;
      mx = max(mx, cur);
      ans.push_back(e.user_id);

      e.id += n;
      e.type = -1;
      e.time += T;
      events.insert(e);
    } else {
      conn[e.user_id]--;
      if (conn[e.user_id] == 0) {
        cur--;
      }
    }
  }

  if (mx < M) {
    cout << "No solution" << endl;
    return 0;
  }

  cout << cnt << endl;
  for (int u : ans) {
    cout << u << '\n';
  }
}