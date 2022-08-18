#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1023456789;

class SegTree {
  int length;
  vector<int> tree;
  vector<int> lend;
  vector<int> rend;

  void update (int vertex) {
    if (vertex == 0) {
      return;
    }
    tree[vertex] = min(tree[2 * vertex], tree[2 * vertex + 1]);
    update(vertex / 2);
  }
  
public:
  SegTree (int _length) {
    length = 1;
    while (length < _length) {
      length *= 2;
    }

    tree = vector<int> (2 * length, INF);
    lend = vector<int> (2 * length);
    rend = vector<int> (2 * length);

    for (int i = length; i < 2 * length; i++) {
      lend[i] = i - length;
      rend[i] = i - length;
    }

    for (int i = length - 1; i >= 1; i--) {
      lend[i] = lend[2 * i];
      rend[i] = rend[2 * i + 1];
    }
  }

  void set (int idx, int val) {
    tree[length + idx] = val;
    update((length + idx) / 2);
  }

  int query (int ql, int qr, int vertex = 1) {
    ql = max(ql, lend[vertex]);
    qr = min(qr, rend[vertex]);

    if (ql > qr) {
      return INF;
    } else if (ql == lend[vertex] && qr == rend[vertex]) {
      return tree[vertex];
    } else {
      return min(query(ql, qr, 2 * vertex), query(ql, qr, 2 * vertex + 1));
    }
  }
};

const int MAX_N = 300005;

vector<int> pops [MAX_N];

void solve () {
  int length;
  cin >> length;

  vector<int> orig (length);
  for (int i = 0; i < length; i++) {
    cin >> orig[i];
  }
  
  vector<int> target (length);
  for (int i = 0; i < length; i++) {
    cin >> target[i];
  }

  auto tempt = target;
  sort(tempt.begin(), tempt.end());
  auto tempo = orig;
  sort(tempo.begin(), tempo.end());
  if (tempt != tempo) {
    cout << "NO" << '\n';
    return;
  }

  for (int i = length - 1; i >= 0; i--) {
    pops[orig[i]].push_back(i);
  }

  SegTree segTree (length);
  for (int i = 0; i < length; i++) {
    segTree.set(i, orig[i]);
  }

  bool ok = true;
  for (int i = 0; i < length; i++) {
    int targetAt = pops[target[i]].back();
    pops[target[i]].pop_back();

    int segMin = segTree.query(0, targetAt);
    if (segMin < target[i]) {
      ok = false;
    }
    segTree.set(targetAt, INF);
  }

  if (ok) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}