#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int T = 1e5;

int ans[T];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int flag = (s[i] == '1');
    for (int x = 0; x < T; x++) {
      if (x >= b && (x - b) % a == 0) {
        flag ^= 1;
      }
      ans[x] += flag;
    }
  }
  int ret = 0;
  for (int i = 0; i < T; i++) ret = max(ret, ans[i]);
  cout << ret << endl;
}