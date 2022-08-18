#include <iostream>
#include <vector>

using namespace std;

struct State {
  int rem, add, minb;

  State () :
    rem(0), add(0), minb(0) {}

  State (int _rem, int _add, int _minb) :
    rem(_rem), add(_add), minb(_minb) {}
};

State merge (State p, State q) {
  if (q.rem > p.add) {
    return State(p.rem + q.rem - p.add, q.add,
                 min(p.minb + p.add - q.add, q.minb));
  } else {
    return State(p.rem, p.add - q.rem + q.add,
                 min(p.minb + q.rem - q.add, q.minb));
  }
}

ostream& operator<< (ostream &out, State p) {
  out << "(" << p.rem << ", " << p.add << ", " << p.minb << ")";
  return out;
}

class SegTree {
  vector<State> tree;
  vector<int> lfend;
  vector<int> rgend;
  int length;

  void update (int vertex) {
    if (vertex == 0) return;
    tree[vertex] = merge(tree[2 * vertex], tree[2 * vertex + 1]);
    update(vertex / 2);
  }

public:
  SegTree (int _length) {
    length = 1;
    while (length < _length) {
      length *= 2;
    }

    tree = vector<State> (2 * length, State());
    lfend = vector<int> (2 * length);
    rgend = vector<int> (2 * length);

    for (int i = length; i < 2 * length; i++) {
      lfend[i] = i - length;
      rgend[i] = i - length;
    }

    for (int i = length - 1; i >= 1; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void set (int idx, State val) {
    tree[length + idx] = val;
    update((length + idx) / 2);
  }

  State query (int ql, int qr, int vertex = 1) {
    ql = max(ql, lfend[vertex]);
    qr = min(qr, rgend[vertex]);

    if (ql > qr) return State(0, 0, 0);
    if (ql == lfend[vertex] && qr == rgend[vertex]) {
      // cout << ql << " " << qr << " " << vertex << " " << tree[vertex] << endl;
      return tree[vertex];
    }
    State ans = merge(query(ql, qr, 2 * vertex), query(ql, qr, 2 * vertex + 1));
    // cout << ql << " " << qr << " " << vertex << " " << ans << endl;
    return ans;
  }

  int last_lz (int r) {
    int ans = 0;
    for (int i = length; i != 0; i /= 2) {
      if (ans + i <= r && query(ans + i, r).minb < 0) {
        ans += i;
      }
    }
    return ans;
  }
};

const int MAX_N = 1e5 + 5;
int ops [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int queryc;
  cin >> queryc;

  SegTree stree (queryc + 5);
  for (int i = 0; i < queryc; i++) {
    int pos, type;
    cin >> pos >> type;

    if (type == 0) {
      ops[pos] = -1;
      stree.set(pos, State(1, 0, 0));
    } else {
      int val;
      cin >> val;

      ops[pos] = val;
      stree.set(pos, State(0, 1, -1));
    }

    State s = stree.query(1, queryc);
    if (s.add == 0) {
      cout << -1 << '\n';
    } else {
      cout << ops[stree.last_lz(queryc)] << '\n'; // TODDO
    }
  }
}