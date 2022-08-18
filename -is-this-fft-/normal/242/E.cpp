#include <iostream>

typedef long long llong;

const int MAX_LEN = 1 << 17;
const int MAX_BIT = 20;

using namespace std;

class segtree {
  int size, *val, *flip, *lend, *rend;

  void init_node (int vertex, int _lend, int _rend) {
    lend[vertex] = _lend;
    rend[vertex] = _rend;
    val[vertex] = 0;
    flip[vertex] = 0;

    if (_rend - _lend > 1) {
      init_node(vertex * 2, _lend, (_lend + _rend) / 2);
      init_node(vertex * 2 + 1, (_lend + _rend) / 2, _rend);
    }
  }

  void propagate (int vertex) {
    if (flip[vertex]) {
      flip[vertex] = false;

      if (rend[vertex] - lend[vertex] > 1) {
        flip[vertex * 2] = !flip[vertex * 2];
        val[vertex * 2] = rend[vertex * 2] - lend[vertex * 2] - val[vertex * 2];
      
        flip[vertex * 2 + 1] = !flip[vertex * 2 + 1];
        val[vertex * 2 + 1] = rend[vertex * 2 + 1] - lend[vertex * 2 + 1] -
          val[vertex * 2 + 1];
      }
    }
  }

  void update_node (int vertex) {
    if (rend[vertex] - lend[vertex] > 1) {
      if (val[vertex] != val[vertex * 2] + val[vertex * 2 + 1]) {
        val[vertex] = val[vertex * 2] + val[vertex * 2 + 1];
        if (vertex != 1) {
          update_node(vertex / 2);
        }
      }
    }
  }

public:
  segtree () {}
  segtree (int _size) {
    size = _size;
    val = new int [size * 2];
    flip = new int [size * 2];
    lend = new int [size * 2];
    rend = new int [size * 2];
    
    init_node(1, 0, size);
  }

  int query (int vertex, int type, int ql, int qr) {
    propagate(vertex);

    ql = max(lend[vertex], ql);
    qr = min(rend[vertex], qr);

    if (ql == lend[vertex] && qr == rend[vertex]) {
      if (type == 1) {
        return val[vertex];
      } else {
        val[vertex] = rend[vertex] - lend[vertex] - val[vertex];
        flip[vertex] = true;

        if (vertex != 1) {
          update_node(vertex / 2);
        }
        return 0;
      }
    } else if (qr - ql <= 0) {
      return 0;
    } else {
      if (rend[vertex] - lend[vertex] > 0) {
        return query(vertex * 2, type, ql, qr) +
          query(vertex * 2 + 1, type, ql, qr);
      } else {
        return 0;
      }
    }
  }
};

segtree stree [MAX_BIT];

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_BIT; i++) {
    stree[i] = segtree (MAX_LEN);
  }

  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    int element;
    cin >> element;

    for (int j = 0; j < MAX_BIT; j++) {
      if (element & 1 << j) {
        stree[j].query(1, 2, i, i + 1);
      }
    }
  }
  
  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int ql, qr;
      cin >> ql >> qr;
      
      llong ans = 0;
      for (int j = 0; j < MAX_BIT; j++) {
        ans += (1LL << j) * (llong) stree[j].query(1, 1, ql - 1, qr);
      }
      cout << ans << '\n';
    } else {
      int ql, qr, xorv;
      cin >> ql >> qr >> xorv;

      for (int j = 0; j < MAX_BIT; j++) {
        if (xorv & 1 << j) {
          stree[j].query(1, 2, ql - 1, qr);
        }
      }
    }
  }
}