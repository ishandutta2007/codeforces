#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
const int L = 22;
bool is_base[N];
int calc[L];
bool used[N*L];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(is_base, is_base+N, 1);
  for (int i = 2; i < N; i++) {
    if (is_base[i]) {
      for (long long j = 1LL*i*i; j < N; j *= i) {
        is_base[j] = 0;
      }
    }
  }

  int n, m;
  cin >> n >> m;
  for (int i = 1; i < L; i++) {
    for (int j = 1; j <= m; j++) {
      used[i*j] = 1;
    }
    calc[i] = accumulate(used, used+i*m+1, 0);
  }

  long long ans = 1;
  for (int i = 2; i <= n; i++) {
    if (!is_base[i]) continue;
    int pw = 1;
    int mx = i;
    while (1LL*mx*i <= n) {
      mx *= i;
      pw++;
    }
    ans += calc[pw];
  }
  cout << ans << '\n';
}