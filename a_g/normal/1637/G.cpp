#include <bits/stdc++.h>
using namespace std;

/* Observe that the end number must be a power of 2 because we cannot go from (p
 * does not divide some number) to (p divides every number).
 *
 * Also observe the transformation (a, b) -> (b-a, b+a) -> (2a, 2b).
 */

const int N = 1e5+5;
int freq[N];

vector<pair<int, int>> ops;

void operate(int a, int b) {
  if (a < b) swap(a, b);
  freq[a]--;
  freq[b]--;
  ops.emplace_back(a, b);
  freq[a+b]++;
  freq[a-b]++;
}

void fold(int n, int scale = 1) {
  if (n <= 2) return;
  int k = 1;
  while (k < n) k <<= 1;
  if (k == n) {
    fold(n-1, scale);
    return;
  }
  for (int i = k/2+1; i <= n; i++) {
    operate(i*scale, (k-i)*scale);
  }
  fold(k-n-1, scale);
  fold(n-k/2, 2*scale);
}

void x2(int a, int b) {
  if (a < b) swap(a, b);
  operate(a, b);
  operate(a-b, a+b);
}

void solve(int n) {
  fold(n);
  int k = 0;
  while ((1<<k) < n) k++;
  for (int i = 0; i < k; i++) {
    if (freq[1<<i] >= 2) {
      operate(1<<i, 1<<i);
      break;
    }
  }
  for (int i = 0; i < k; i++) {
    while (freq[1<<i]) {
      x2(0, 1<<i);
    }
  }
  while (freq[0]) {
    operate(0, 1<<k);
  }
  return;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << "-1\n";
      continue;
    }
    fill(freq+1, freq+n+1, 1);
    solve(n);
    cout << ops.size() << '\n';
    for (pair<int, int> p: ops) {
      cout << p.first << " " << p.second << '\n';
    }
    ops.clear();
    fill(freq+1, freq+2*n+1, 0);
  }
}