#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_P = 1e6 + 5;

int factor [MAX_P];

int norm (int x) {
  int last = -1;
  int ans = 1;
  while (x != 1) {
    int f = factor[x];
    x /= f;

    if (f == last) {
      ans /= f;
      last = -1;
    } else {
      ans *= f;
      last = f;
    }
  }
  return ans;
}

void solve () {
  map<int, int> cnt;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    x = norm(x);
    cnt[x]++;
  }

  int ans0 = 0;
  int to1 = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    ans0 = max(ans0, it->second);
    if (it->second % 2 == 0 && it->first != 1) {
      to1 += it->second;
    }
  }

  int ans1 = max(ans0, to1 + cnt[1]);

  int qc;
  cin >> qc;
  for (int i = 0; i < qc; i++) {
    ll w;
    cin >> w;

    if (w == 0) {
      cout << ans0 << '\n';
    } else {
      cout << ans1 << '\n';
    }
  }
}

int main () {
  for (int i = 2; i < MAX_P; i++) {
    if (factor[i] == 0) {
      for (int j = i; j < MAX_P; j += i) {
        factor[j] = i;
      }
    }
  }
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}