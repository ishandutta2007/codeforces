#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX_N = 1 << 17;

double stree [2 * MAX_N];

void update (int vertex) {
  if (vertex == 0) return;
  stree[vertex] = stree[2 * vertex] * stree[2 * vertex + 1];
  update(vertex / 2);
}

void setval (int vertex, double val) {
  stree[MAX_N + vertex] = val;
  update((MAX_N + vertex) / 2);
}

struct Event {
  int time, type; // -1: beginning, 0: mushroom, 1: end
  int val; // power if mushroom,
  int id;

  Event (int _time, int _type, int _val, int _id) :
    time(_time), type(_type), val(_val), id(_id) {}
};

bool operator< (Event p, Event q) {
  return make_pair(p.time, p.type) < make_pair(q.time, q.type);
}

int main () {
  for (int i = 0; i < 2 * MAX_N; i++) {
    stree[i] = 1;
  }
  
  ios::sync_with_stdio(false);
  
  int treec, mushc;
  cin >> treec >> mushc;

  vector<Event> events;
  for (int i = 0; i < treec; i++) {
    int a, h, l, r;
    cin >> a >> h >> l >> r;

    int mid = 100 - l - r;
    events.push_back(Event(a - h, -1, r + mid, i));
    events.push_back(Event(a - 1, 1, r + mid, i));
    events.push_back(Event(a + 1, -1, l + mid, i));
    events.push_back(Event(a + h, 1, l + mid, i));
  }

  for (int i = 0; i < mushc; i++) {
    int b, z;
    cin >> b >> z;
    events.push_back(Event(b, 0, z, 0));
  }

  sort(events.begin(), events.end());

  double ans = 0;
  for (Event e : events) {
    if (e.type == -1) {
      setval(e.id, (double) e.val / 100);
    } else if (e.type == 0) {
      ans += stree[1] * e.val;
    } else {
      setval(e.id, 1);
    }
  }

  cout << fixed << setprecision(12) << ans << endl;
}