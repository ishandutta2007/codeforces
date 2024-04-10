#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int t, d;
bool vis[N];

int main() {
  for (int i = 2; i * i < N; ++i) if (!vis[i]) {
    for (int j = i * i; j < N; j += i) vis[j] = 1;
  }
  cin >> t;
  while (t--) {
    scanf("%d", &d);
    int p = d + 1;
    while (vis[p]) ++p;
    int q = d + p;
    while (vis[q]) ++q;
    long long ans = (long long) p * q;
    printf("%lld\n", ans);
  }
  return 0;
}