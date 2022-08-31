#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Segtree {
  int n;
  vector<int> tree;
  vector<int> lfend;
  vector<int> rgend;

  void update (int u) {
    if (u == 0) {
      return;
    }

    tree[u] = tree[2 * u] ^ tree[2 * u + 1];
    update(u / 2);
  }
  
public:
  Segtree () {}
  
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

  int query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return 0;
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      return tree[u];
    }

    return query(ql, qr, 2 * u) ^ query(ql, qr, 2 * u + 1);
  }

  void flip (int u) {
    tree[n + u] = !tree[n + u];
    update((n + u) / 2);
  }
};

const int MAX_LG = 18;
const int MAX_N = 1 << MAX_LG;

struct Query {
  int l, r, ans;
};

Query queries [MAX_N];

struct Event {
  int time, type;
  // type = -(query_id) if opens, +(query_id) if closes, 0 if update
};

bool operator< (Event p, Event q) {
  if (p.time != q.time) {
    return p.time < q.time;
  }

  return p.type < q.type;
}

Segtree trees [MAX_LG];

int main () {
  for (int i = 0; i < MAX_LG; i++) {
    trees[i] = Segtree(1 << (i + 1));
  }
  
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  vector<Event> events;
  for (int i = 0; i < n; i++) {
    Event ev;
    cin >> ev.time;
    ev.type = 0;

    events.push_back(ev);
  }

  int qc;
  cin >> qc;

  for (int i = 1; i <= qc; i++) {
    cin >> queries[i].l >> queries[i].r;

    Event op;
    op.time = queries[i].l;
    op.type = -i;
    events.push_back(op);

    Event cl;
    cl.time = queries[i].r;
    cl.type = i;
    events.push_back(cl);
  }

  sort(events.begin(), events.end());

  for (auto ev : events) {
    if (ev.type == 0) {
      for (int k = 0; k < MAX_LG; k++) {
        trees[k].flip(ev.time % (1 << (k + 1)));
      }
    } else {
      int qid = abs(ev.type);
      int l = queries[qid].l;
      
      for (int k = 0; k < MAX_LG; k++) {
        int len = 1 << (k + 1);
        int ql = (l + len / 2) % len;
        int qr = (l + len - 1) % len;

        int cur = 0;
        if (ql <= qr) {
          cur ^= trees[k].query(ql, qr);
        } else {
          cur ^= trees[k].query(0, qr);
          cur ^= trees[k].query(ql, len - 1);
        }

        queries[qid].ans ^= cur << k;
      }
    }
  }

  for (int i = 1; i <= qc; i++) {
    if (queries[i].ans == 0) {
      cout << "B";
    } else {
      cout << "A";
    }
  }
  cout << endl;
}