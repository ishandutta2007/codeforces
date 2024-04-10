#include <bits/stdc++.h>

using namespace std;

void stress() {

}

bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return (x != 1);
}

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> b(n);
  map <int, long long> t;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    t[i - b[i]] += b[i];
  }
  long long ans = 0;
  for (auto c : t) {
    ans = max(ans, c.second);
  }
  cout << ans << endl;
}