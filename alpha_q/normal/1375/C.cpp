#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    vector <int> vec(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &vec[i]);
    }
    puts((vec[0] < vec[n - 1]) ? "YES" : "NO");
  }
  return 0;
}