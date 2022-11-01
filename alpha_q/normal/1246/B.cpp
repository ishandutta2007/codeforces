#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int N = 100010;

int n, k;
long long a[N], sp[N];
map <vector <pii>, int> f;

int main() {
  for (int i = 2; i * i < N; ++i) {
    if (sp[i]) continue; sp[i] = i;
    for (int j = i * i; j < N; j += i) {
      if (!sp[j]) sp[j] = i;
    }
  }
  for (int i = 2; i < N; ++i) if (!sp[i]) sp[i] = i;
  cin >> n >> k;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    int x = a[i];
    vector <pii> one, two;
    while (x > 1) {
      int p = sp[x], e = 0;
      while (x % p == 0) x /= p, ++e;
      e %= k; 
      if (e) {
        one.emplace_back(p, e);
        e = k - e; 
        two.emplace_back(p, e);
      }
    }
    ans += f[two]; ++f[one];
  }
  cout << ans << '\n';
  return 0;
}