#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
long long cnt[N];
long long k;
// cnt[i] = number of substrings with f(s) = i
// k = sum(i*cnt[i])

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  long long ans = 0;
  int cur = 0;
  cnt[0] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cur++;
    }
    else {
      cur = 0;
    }
    if (cur) {
      k += cnt[cur-1]-1;
      cnt[cur] += cnt[cur-1]-1;
      cnt[cur-1] = 1;
    }
    cnt[cur]++;
    k += cur;
    ans += k;
  }
  cout << ans << '\n';
}