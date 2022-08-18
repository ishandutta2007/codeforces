#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAX_N = 1e6 + 5;

ll arr [MAX_N];
ll pref [MAX_N];

int root [MAX_N];
int curl [MAX_N];
int curr [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[v] = u;
  curl[u] = min(curl[u], curl[v]);
  curr[u] = max(curr[u], curr[v]);
}

void try_around (int u);

void try_merge (int u, int v) {
  if (curr[u] + 1 == curl[v]) {
    if ((ld) (pref[curr[u]] - pref[curl[u] - 1]) / (curr[u] - curl[u] + 1) >
        (ld) (pref[curr[v]] - pref[curl[u] - 1]) / (curr[v] - curl[u] + 1)) {
      merge(u, v);

      try_around(u);
    }
  }
}

void try_around (int u) {
  int lu = find(curl[u] - 1);
  int ru = find(curr[u] + 1);

  if (lu != 0) try_merge(lu, u);
  if (ru != 0) try_merge(u, ru);
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    root[i] = i;
    curl[i] = i;
    curr[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + arr[i];
  }

  for (int i = 1; i <= n; i++) {
    try_around(i);
  }

  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      int l = curl[i];
      int r = curr[i];

      ld cur = (ld) (pref[r] - pref[l - 1]) / (r - l + 1);

      for (int j = l; j <= r; j++) {
        cout << fixed << setprecision(12) << cur << '\n';
      }
    }
  }
}