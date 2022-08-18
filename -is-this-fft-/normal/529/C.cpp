#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 5;

class Segtree {
  int n;
  vector<int> tree;
  vector<int> lfend;
  vector<int> rgend;

  void update (int u) {
    if (u == 0) return;
    tree[u] = min(tree[2 * u], tree[2 * u + 1]);
    update(u / 2);
  }

public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<int> (2 * n, 0);
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void set (int pos, int val) {
    tree[n + pos] = val;
    update((n + pos) / 2);
  }

  int query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) return INF;
    if (ql == lfend[u] && qr == rgend[u]) return tree[u];
    return min(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }
};

struct Square {
  int x, y;
};

struct Query {
  int x0, y0, x1, y1;
};

struct Event {
  int type; // 0 - update, 1 - query
  int id; // id of the query
  int time, atl;
  int l, r; // l is also used as pos
};

bool operator< (Event p, Event q) {
  if (p.time != q.time) {
    return p.time < q.time;
  }

  return p.type < q.type;
}

const int MAX_N = 1e5 + 5;
const int MAX_Q = 2e5 + 5;

bool ans [MAX_Q];

void process (vector<Event> &events) {
  sort(events.begin(), events.end());

  Segtree tree (MAX_N);
  for (auto e : events) {
    if (e.type == 0) {
      tree.set(e.l, e.time);
    } else {
      int mn = tree.query(e.l, e.r);
      if (mn >= e.atl) {
        ans[e.id] = true;
      }
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, m, K, qc;
  cin >> n >> m >> K >> qc;

  vector<Square> rooks (K);
  for (int i = 0; i < K; i++) {
    cin >> rooks[i].x >> rooks[i].y;
  }

  vector<Query> qs (qc);
  for (int i = 0; i < qc; i++) {
    cin >> qs[i].x0 >> qs[i].y0 >> qs[i].x1 >> qs[i].y1;
  }

  {
    vector<Event> events;
    for (auto rook : rooks) {
      Event event;
      event.type = 0;
      event.time = rook.y;
      event.l = rook.x;

      events.push_back(event);
    }

    for (int i = 0; i < (int) qs.size(); i++) {
      auto q = qs[i];
      
      Event event;
      event.type = 1;
      event.time = q.y1;
      event.atl = q.y0;
      event.id = i;
      event.l = q.x0;
      event.r = q.x1;

      events.push_back(event);
    }

    process(events);
  }

  {
    vector<Event> events;
    for (auto rook : rooks) {
      Event event;
      event.type = 0;
      event.time = rook.x;
      event.l = rook.y;

      events.push_back(event);
    }

    for (int i = 0; i < (int) qs.size(); i++) {
      auto q = qs[i];
      
      Event event;
      event.type = 1;
      event.time = q.x1;
      event.atl = q.x0;
      event.id = i;
      event.l = q.y0;
      event.r = q.y1;

      events.push_back(event);
    }

    process(events);    
  }

  for (int i = 0; i < qc; i++) {
    if (!ans[i]) cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }
}