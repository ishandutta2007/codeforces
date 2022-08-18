#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void success () {
  cout << "YES" << '\n';
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);

  int n, m, K;
  cin >> n >> m >> K;

  vector<int> A (n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  
  vector<int> B (m);
  for (int i = 0; i < m; i++) {
    cin >> B[i];
  }
  sort(B.begin(), B.end());

  if (A.size() > B.size()) {
    success();
  }

  while (!A.empty()) {
    if (A.back() > B.back()) {
      success();
    }

    A.pop_back();
    B.pop_back();
  }

  cout << "NO" << '\n';
}