#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 10;
pair<int, int> A[N];
int pos[N];
int n, m;
int solve(int start, int len) {
  // binary search for R
  int R = upper_bound(A + start, A + n + 1, make_pair(A[start].first + len, N)) - A - 1;
  len = len - (A[R].first - A[start].first);
  // binary search for L
  int L = upper_bound(A + 1, A + 1 + R, make_pair(A[R].first - len, 0)) - A;
  len = len - (A[R].first - A[L].first);
  // Found L and R
  if (L == start && R == start) return start;
  if (L != R) len = len % (2 * (A[R].first - A[L].first));
  return solve(L, len);
}

bool cmp(int x, int y) { return A[x] < A[y]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A + 1, A + 1 + n);
  for (int i = 1; i <= n; i++) pos[A[i].second] = i;
  while (m--) {
    int start, len;
    cin >> start >> len;
    int ans = solve(pos[start], len);
    cout << A[ans].second << "\n";
  }
  return 0;
}