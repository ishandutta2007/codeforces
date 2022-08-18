#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Event {
  int l, r, K, type, id;
};

bool operator< (Event p, Event q) {
  if (p.l != q.l) {
    return p.l < q.l;
  }
  if (p.type != q.type) {
    return p.type < q.type;
  }
  return p.id < q.id;
}

const int MAX_N = 1e5 + 5;

int ans [MAX_N];

void failure () {
  cout << "NO" << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  vector<Event> events;
  for (int i = 0; i < n; i++) {
    Event e;
    e.type = 1;
    e.id = i;
      
    cin >> e.l >> e.r;
    events.push_back(e);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    Event e;
    e.type = 0;
    e.id = i;

    cin >> e.l >> e.r >> e.K;
    events.push_back(e);
  }

  sort(events.begin(), events.end());

  map<pair<int, int>, int> actors;
  for (Event e : events) {
    if (e.type == 0) {
      actors[make_pair(e.r, e.id)] = e.K;
    } else {
      auto lb = actors.lower_bound(make_pair(e.r, -1));
      if (lb == actors.end()) {
        failure();
      }
      ans[e.id] = lb->first.second;
      lb->second--;
      if (lb->second == 0) {
        actors.erase(lb);
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
}