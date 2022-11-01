#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int t, n, fix[N]; ll a[N];

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }
    vector <int> id;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", fix + i);
      if (!fix[i]) id.emplace_back(i);
    }
    sort(id.begin(), id.end(), [] (int i, int j) {
      return a[i] > a[j];
    });
    int at = 0;
    for (int i = 1; i <= n; ++i) {
      if (fix[i]) printf("%lld ", a[i]);
      else printf("%lld ", a[id[at++]]);
    }
    puts("");
  }
  return 0;
}