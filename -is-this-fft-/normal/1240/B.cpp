#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

struct segtree {
  vector<int> tree;
  vector<int> lfend;
  vector<int> rgend;
  int length;

  void update (int vertex) {
    if (vertex == 0) return;
    tree[vertex] = min(tree[2 * vertex], tree[2 * vertex + 1]);
    update(vertex / 2);
  }
  
public:
  segtree (int _length, int init) {
    length = 1;
    while (length < _length) {
      length *= 2;
    }

    tree = vector<int> (2 * length, init);
    lfend = vector<int> (2 * length);
    rgend = vector<int> (2 * length);
    for (int i = length; i < 2 * length; i++) {
      lfend[i] = i - length;
      rgend[i] = i - length;
    }

    for (int i = length - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  void set (int idx, int val) {
    tree[length + idx] = val;
    update((length + idx) / 2);
  }

  int get (int ql, int qr, int vertex = 1) {
    ql = max(ql, lfend[vertex]);
    qr = min(qr, rgend[vertex]);

    if (ql > qr) return INF;
    if (ql == lfend[vertex] && qr == rgend[vertex]) return tree[vertex];
    return min(get(ql, qr, 2 * vertex), get(ql, qr, 2 * vertex + 1));
  }
};

const int MAX_N = 3e5 + 5;

int arr [MAX_N];
int rangel [MAX_N], ranger [MAX_N];

void solve () {
  int length;
  cin >> length;
  
  map<int, int> compr;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    compr[arr[i]] = 0;
  }

  int colorc = 0;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = colorc;
    colorc++;
  }

  for (int i = 0; i < length; i++) {
    arr[i] = compr[arr[i]];
  }

  for (int i = 0; i < colorc; i++) {
    rangel[i] = length + 5;
    ranger[i] = -1;
  }

  for (int i = 0; i < length; i++) {
    rangel[arr[i]] = min(rangel[arr[i]], i);
    ranger[arr[i]] = max(ranger[arr[i]], i);
  }

  segtree st (length + 5, INF);
  segtree forb (length + 5, INF);
  for (int i = colorc - 1; i >= 0; i--) {
    int forbi = st.get(0, ranger[i]);
    st.set(rangel[i], i);
    forb.set(i, forbi);
  }

  int ans = INF;
  for (int i = 0; i < colorc; i++) {
    int right_cut = forb.get(i, colorc - 1);
    if (right_cut == INF) {
      ans = min(ans, i);
    } else {
      ans = min(ans, i + colorc - right_cut);
    }
  }
  cout << ans << endl;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}