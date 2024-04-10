#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N], b[N];

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  if (n < 3) {
    cout << "0\n";
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    puts("");
    return 0;
  }
  sort(a + 1, a + n + 1);
  int at = 1;
  for (int i = 2; i < n; i += 2) {
    b[i] = a[at++];
  }
//  cerr << "yo\n";
  vector <int> remaining;
  for (int i = 1; i < n; i += 2) {
    int req = max(b[i - 1], b[i + 1]);
    while (at <= n and a[at] <= req) {
      remaining.emplace_back(a[at++]);
    }
    if (at <= n) b[i] = a[at++];
    else break;
  }
  while (at <= n) remaining.emplace_back(a[at++]);
//  cerr << "yo\n";
  at = 0;
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
//      cerr << at << " " << remaining.size() << '\n';
      b[i] = remaining[at++];
    }
  }
  int ans = 0;
  for (int i = 2; i < n; ++i) {
    if (b[i] < b[i - 1] and b[i] < b[i + 1]) {
      ++ans;
    }
  }
//  cerr << "yo\n";
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i) {
    printf("%d ", b[i]);
  }
  cout << '\n';
  return 0;
}