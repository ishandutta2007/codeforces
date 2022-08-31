#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

const int MAX_A = 1e7 + 5;
const int MAX_N = 1e6 + 5;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll sq (ll x) {
  return x * x;
}

bool is_perfect (ll x) {
  ll sqx = sqrt(x);
  if (sqx * sqx == x) return true;
  if ((sqx - 1) * (sqx - 1) == x) return true;
  if ((sqx + 1) * (sqx + 1) == x) return true;
  return false;
}

int arr [MAX_N];
int pos [MAX_A];
int root [MAX_N];
int height [MAX_N];

int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  if (u != v) {
    if (height[u] < height[v]) {
      swap(u, v);
    }

    root[v] = u;
    if (height[u] == height[v]) {
      height[u]++;
    }
  }
}

int main () {
  for (int i = 1; i < MAX_N; i++) {
    root[i] = i;
  }
  
  ios::sync_with_stdio(false);
  int length;
  cin >> length;

  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }

  for (int m = 2; m * m < 3 * MAX_A; m++) {
    for (int n = 1; n < m; n++) {
      if (m % 2 == 0 || n % 2 == 0) {
        if (gcd(m, n) == 1) {
          int a = sq(m) - sq(n);
          int b = 2 * m * n;
          int c = sq(m) + sq(n);

          if (a < MAX_A && b < MAX_A) {
            if (pos[a] && pos[b]) {
              merge(pos[a], pos[b]);
            }
          }

          if (a < MAX_A && c < MAX_A) {
            if (pos[a] && pos[c]) {
              merge(pos[a], pos[c]);
            }
          }

          if (b < MAX_A && c < MAX_A) {
            if (pos[b] && pos[c]) {
              merge(pos[b], pos[c]);
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= length; i++) {
    if (find(i) == i) {
      ans++;
    }
  }

  cout << ans << endl;
}