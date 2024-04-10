#include <iostream>
#include <vector>

#define rend ___rend

using namespace std;

const int MAX_N = 1 << 13;

int arr [MAX_N];

int tree [2 * MAX_N];
int lend [2 * MAX_N];
int rend [2 * MAX_N];

void update (int u, int val) {
  for (int k = u + MAX_N; k != 0; k /= 2) {
    if (val <= tree[k]) return;
    tree[k] = val;
  }
}

int query (int ql, int qr, int u = 1) {
  ql = max(ql, lend[u]);
  qr = min(qr, rend[u]);

  if (ql > qr) return 0;
  if (ql == lend[u] && qr == rend[u]) return tree[u];
  return max(query(ql, qr, 2 * u),
             query(ql, qr, 2 * u + 1));
}

const int MAX_Q = 1e5 + 5;

struct Query {
  int l, r, id;
};

int ans [MAX_Q];
vector<Query> qs [MAX_N];

const int MAX_S = 5e3 + 5;

int pref [MAX_S][MAX_S]; // <start, length>

int msd (int n) {
  return 1 << (31 - __builtin_clz(n));
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = MAX_N; i < 2 * MAX_N; i++) {
    lend[i] = i - MAX_N;
    rend[i] = i - MAX_N;
  }

  for (int i = MAX_N - 1; i > 0; i--) {
    lend[i] = lend[2 * i];
    rend[i] = rend[2 * i + 1];
  }

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    Query q;
    cin >> q.l >> q.r;
    q.id = i;

    qs[q.l].push_back(q);
  }

  for (int l = n; l >= 1; l--) {
    pref[l][1] = arr[l];
    for (int k = 2; l + k - 1 <= n; k++) {
      int ms = msd(k);
      if (ms == k) {
        pref[l][k] = pref[l][k / 2] ^ pref[l + k / 2][k / 2];
      } else {
        pref[l][k] = pref[l][k - ms] ^ pref[l + ms][k - ms];
      }
    }

    for (int k = 1; l + k - 1 <= n; k++) {
      update(l + k - 1, pref[l][k]);
    }

    for (Query q : qs[l]) {
      ans[q.id] = query(q.l, q.r);
    }
  }

  for (int i = 0; i < qc; i++) {
    cout << ans[i] << '\n';
  }
}