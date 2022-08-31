#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1 << 19;
const int maxlg = 20;

int perm [maxn];
int arr [maxn];
int prev_val [maxn];
int last_seen [maxn];
vector<int> children [maxn];
int jmp [maxn][maxlg];

void build (int vertex, int parent) {
  jmp[vertex][0] = parent;
  for (int i = 1; i < maxlg; i++) {
    jmp[vertex][i] = jmp[jmp[vertex][i - 1]][i - 1];
  }

  for (int nxt : children[vertex]) {
    if (nxt != parent) {
      build(nxt, vertex);
    }
  }
}

int jump_n (int u, int n) {
  for (int i = 0; i < maxlg; i++) {
    if (n & 1 << i) {
      u = jmp[u][i];
    }
  }
  return u;
}

int src_tree [2 * maxn];
int lfend [2 * maxn];
int rgend [2 * maxn];

int query (int ql, int qr, int vertex) {
  ql = max(ql, lfend[vertex]);
  qr = min(qr, rgend[vertex]);

  if (ql > qr) {
    return 0;
  } else if (ql == lfend[vertex] && qr == rgend[vertex]) {
    return src_tree[vertex];
  } else {
    return max(query(ql, qr, 2 * vertex),
               query(ql, qr, 2 * vertex + 1));
  }
}

int main () {
  int permlen, arrlen, queryc;
  cin >> permlen >> arrlen >> queryc;

  for (int i = 1; i <= permlen; i++) {
    cin >> perm[i];
  }
  prev_val[perm[1]] = perm[permlen];
  for (int i = 2; i <= permlen; i++) {
    prev_val[perm[i]] = perm[i - 1];
  }

  /*
  for (int i = 1; i <= permlen; i++) {
    cout << prev_val[i] << " ";
  }
  cout << endl;
  */

  for (int i = 1; i <= arrlen; i++) {
    cin >> arr[i];

    children[last_seen[prev_val[arr[i]]]].push_back(i);
    last_seen[arr[i]] = i;
  }

  /*
  for (int i = 0; i <= arrlen; i++) {
    cout << i << ": ";
    for (int nxt : children[i]) {
      cout << nxt << " ";
    }
    cout << endl;
  }
  */
  
  build(0, 0);

  for (int i = 1; i <= arrlen; i++) {
    src_tree[maxn + i] = jump_n(i, permlen - 1);
    // cerr << src_tree[maxn + i] << " ";
  }
  // cerr << endl;

  for (int i = 0; i < maxn; i++) {
    lfend[maxn + i] = i;
    rgend[maxn + i] = i;
  }

  for (int i = maxn - 1; i >= 1; i--) {
    lfend[i] = lfend[2 * i];
    rgend[i] = rgend[2 * i + 1];
    src_tree[i] = max(src_tree[2 * i], src_tree[2 * i + 1]);
  }

  for (int i = 0; i < queryc; i++) {
    int l, r;
    cin >> l >> r;

    cout << (query(l, r, 1) >= l);
  }
  cout << endl;
}