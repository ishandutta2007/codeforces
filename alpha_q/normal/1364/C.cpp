#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1000000;

vector <int> infs;
int n, a[N], b[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  int cur = 0;
  for (int i = 1; i <= n; ++i) {
    infs.emplace_back(i);
    if (a[i] ^ cur) {
      // 0, 1, 2, ..., cur-1, __, inf
      assert(a[i] > cur);
      int diff = a[i] - cur;
      if (infs.size() < diff) {
        puts("-1");
        return 0;
      }
      int at = cur;
      while (diff--) {
        b[infs.back()] = at++;
        infs.pop_back();
      }
      cur = a[i];
    }
  }
  while (!infs.empty()) {
    b[infs.back()] = INF;
    infs.pop_back();
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", b[i]);
  }
  cout << '\n';
  return 0;
}