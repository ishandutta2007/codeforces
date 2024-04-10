#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1 << 19;

struct elem {
  int cl, op; // )**{cl} + (**{op}

  elem (int _cl = 0, int _op = 0) :
    cl(_cl), op(_op) {}
};

elem merge (elem l, elem r) {
  if (l.op > r.cl) {
    return elem(l.cl, r.op + l.op - r.cl);
  } else {
    return elem(l.cl + r.cl - l.op, r.op);
  }
}

elem tree [2 * MAX_N];

void update (int u) {
  if (u == 0) return;

  tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
  update(u / 2);
}

void set (int idx, elem val) {
  tree[MAX_N + idx] = val;
  update((MAX_N + idx) / 2);
}

int bomb [MAX_N];
int brack [MAX_N];

void set_as (int idx) {
  if (!bomb[idx] && !brack[idx]) set(idx, elem(0, 0));
  if (bomb[idx] && !brack[idx]) set(idx, elem(1, 0));
  if (!bomb[idx] && brack[idx]) set(idx, elem(0, 1));
  if (bomb[idx] && brack[idx]) set(idx, elem(0, 0));
}

int arr [MAX_N];
int pos [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  int nxt = n;
  for (int i = 1; i <= n; i++) {
    while (tree[1].op == 0) {
      brack[pos[nxt]] = 1;
      set_as(pos[nxt]);
      nxt--;
    }

    cout << nxt + 1 << " ";

    int q;
    cin >> q;
    bomb[q] = 1;
    set_as(q);
  }
  cout << endl;
}