#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N];

int main() {
  cin >> n;
  int par = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    par ^= (a[i] & 1);
  }
  if (par) {
    puts("NO");
    return 0;
  }
  sort(a + 1, a + n + 1);
  long long yo = 0;
  for (int i = 1; i < n; ++i) {
    yo += (long long) a[i];
  }
  if (yo < a[n]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}