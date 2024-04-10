#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> v, int n) {
  sort(v.begin(), v.end(), greater <int> ());
  while (!v.empty() && v.back() < 2)
    v.pop_back();
  return !v.empty() && accumulate(v.begin(), v.begin() + min((int)v.size(), n / 2), 0ll) >= n;
}

bool solve() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  vector <int> rows, cols;
  while (K--) {
    int a;
    scanf("%d", &a);
    rows.push_back(a / M);
    cols.push_back(a / N);
  }
  return check(rows, N) || check(cols, M);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    puts(solve() ? "Yes" : "No");
  return 0;
}