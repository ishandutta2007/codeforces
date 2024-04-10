#include <iostream>
#include <vector>

using namespace std;

int clamp (int x) {
  return min(1, x);
}

const int MAX_LG = 30;
int solve (const vector<int> &vs, int k) {
  if (vs.empty()) {
    return 0;
  }

  if (k < 0) {
    return 1;
  }

  vector<int> zeros, ones;
  for (int u : vs) {
    if (u & 1 << k) {
      ones.push_back(u);
    } else {
      zeros.push_back(u);
    }
  }

  int L = solve(zeros, k - 1);
  int R = solve(ones, k - 1);
  return max(L + clamp(R), clamp(L) + R);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> vs (n);
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
  }

  cout << n - solve(vs, MAX_LG) << '\n';
}