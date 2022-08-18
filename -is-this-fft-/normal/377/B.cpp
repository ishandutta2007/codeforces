#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

template<typename T>
using ipq = priority_queue<T, vector<T>, greater<T>>;

struct Event {
  int time; // complexity of the bug or person
  int cost; // -1 if bug
  int id;
};

Event bug (int comp, int id) {
  Event e;
  e.time = comp;
  e.cost = -1;
  e.id = id;
  return e;
}

Event stud (int skill, int cost, int id) {
  Event e;
  e.time = skill;
  e.cost = cost;
  e.id = id;
  return e;
}

bool operator< (Event e, Event f) {
  if (e.time != f.time) {
    return e.time > f.time;
  }

  return e.cost > f.cost;
}

const int MAX_N = 1 << 17;

bool can (const vector<Event> evs, int days, int cap, bool build, vector<int> &out) {
  int buf = 0;
  vector<int> bufv;
  
  ipq<pair<int, int>> Q; // <cost, id>
  for (auto e : evs) {
    if (e.cost == -1) {
      if (buf == 0) {
        if (Q.empty()) {
          return false;
        }

        auto pr = Q.top();
        Q.pop();

        cap -= pr.first;
        buf += days;
        for (int i = 0; i < days && bufv.size() < MAX_N; i++) {
          bufv.push_back(pr.second);
        }
        
        if (cap < 0) {
          return false;
        }
      }
      buf--;
      out[e.id] = bufv.back();
      bufv.pop_back();
    } else {
      Q.push(make_pair(e.cost, e.id));
    }
  }
  return true;
}

int comp [MAX_N];
int skill [MAX_N];
int cost [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m, cap;
  cin >> n >> m >> cap;

  vector<Event> events;
  for (int i = 1; i <= m; i++) {
    cin >> comp[i];
    events.push_back(bug(comp[i], i));
  }

  for (int i = 1; i <= n; i++) {
    cin >> skill[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
    events.push_back(stud(skill[i], cost[i], i));
  }
  sort(events.begin(), events.end());

  vector<int> out (m + 1, 0);
  if (!can(events, m, cap, false, out)) {
    cout << "NO" << endl;
    return 0;
  }

  int dayc = 0;
  for (int k = MAX_N; k != 0; k /= 2) {
    if (!can(events, dayc + k, cap, false, out)) {
      dayc += k;
    }
  }
  dayc++;

  can(events, dayc, cap, true, out);
  cout << "YES" << endl;
  for (int i = 1; i <= m; i++) {
    cout << out[i] << " ";
  }
  cout << endl;
}