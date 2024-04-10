#include <iostream>
#pragma GCC optimize ("Ofast")

using namespace std;

typedef long long ll;

const int MAX_N = 1 << 18;
const int INF = 1e9 + 5;

ll tree [2 * MAX_N];
int mn [2 * MAX_N];
int lfend [2 * MAX_N];
int rgend [2 * MAX_N];
ll ass [2 * MAX_N]; // -1 if no assign
int len [2 * MAX_N];

void propagate (int u) {
  if (ass[u] == -1) return;

  if (len[u] > 1) {
    ass[2 * u] = ass[u];
    ass[2 * u + 1] = ass[u]; // overwrite old merge requests
  }
  tree[u] = (ll) len[u] * ass[u];
  mn[u] = ass[u];
  ass[u] = -1;
}

void update (int ql, int qr, ll val, int u = 1) {
  propagate(u);
  
  ql = max(ql, lfend[u]);
  qr = min(qr, rgend[u]);

  if (ql > qr) return;
  if (ql == lfend[u] && qr == rgend[u]) {
    ass[u] = val;
    propagate(u);
    return;
  }

  update(ql, qr, val, 2 * u);
  update(ql, qr, val, 2 * u + 1);
  tree[u] = tree[2 * u] + tree[2 * u + 1];
  mn[u] = min(mn[2 * u], mn[2 * u + 1]);
}

ll get (int ql, int qr, int u = 1) {
  propagate(u);

  ql = max(ql, lfend[u]);
  qr = min(qr, rgend[u]);

  if (ql > qr) return 0;
  if (ql == lfend[u] && qr == rgend[u]) {
    return tree[u];
  }
  return get(ql, qr, 2 * u) + get(ql, qr, 2 * u + 1);
}

void init () {
  for (int i = MAX_N; i < 2 * MAX_N; i++) {
    ass[i] = -1;
    len[i] = 1;
    lfend[i] = i - MAX_N;
    rgend[i] = i - MAX_N;
  }

  for (int i = MAX_N - 1; i >= 1; i--) {
    ass[i] = -1;
    len[i] = 2 * len[2 * i];
    lfend[i] = lfend[2 * i];
    rgend[i] = rgend[2 * i + 1];
  }
}

int first_val (ll x, int u) {
  if (len[u] == 1) {
    return lfend[u] - 1;
  }

  propagate(2 * u);

  if (mn[2 * u] <= x) {
    return first_val(x, 2 * u);
  }

  if (mn[u] > x) {
    return rgend[u];
  }
  
  propagate(2 * u + 1);
  return first_val(x, 2 * u + 1);
}

// finds the first position where the tree value is <= x
int first_val (ll x) {
  return first_val(x, 1) + 1;
}

int first_sum (ll x, ll added, int u) {
  if (len[u] == 1) {
    return lfend[u] - 1;
  }

  propagate(2 * u);
  if (added + tree[2 * u] > x) {
    return first_sum(x, added, 2 * u);
  }

  if (added + tree[u] <= x) {
    return rgend[u];
  }
  
  added += tree[2 * u];
  propagate(2 * u + 1);
  return first_sum(x, added, 2 * u + 1);
}

// finds the first position where the prefix sum is > x
int first_sum (ll x) {
  return first_sum(x, 0, 1) + 1;
}

int walk_query (int pos, ll y, int n) {
  pos = max(pos, first_val(y));
  if (pos >= n) {
    return 0;
  }

  ll psum = get(0, pos - 1);
  ll npos = min(n, first_sum(y - psum));
  ll nsum = get(0, npos - 1);
  return npos - pos + walk_query(npos, y - (nsum - psum), n);
}

void update_query (int pos, ll y) {
  int l = first_val(y);
  update(l, pos, y);
}

int main () {
  ios::sync_with_stdio(false);

  init();

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    update(i, i, a);
  }

  for (int i = 0; i < qc; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    x--;

    if (t == 1) {
      update_query(x, y);
    } else {
      cout << walk_query(x, y, n) << '\n';
    }
  }
}