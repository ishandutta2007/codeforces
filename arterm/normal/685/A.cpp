#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

int len(int n) {
  if (n == 0)
    return 1;

  int ans = 0;
  while (n > 0) {
    ++ans;
    n /= 7;
  }

  return ans;
}

int n, m;
int lenn, lenm;

int val(string s) {
  int ans = 0;
  for (char c : s) {
    ans *= 7;
    ans += c - '0';
  }
  return ans;
}

bool good(string s) {
  int x = val(s.substr(0, lenn));
  int y = val(s.substr(lenn, lenm));
  return x < n && y < m;
}

void read() {
  cin >> n >> m;
  lenn = len(n - 1);
  lenm = len(m - 1);
}


void kill() {
  string s = "0123456";
  
  int b = 1 * 2 * 3 * 4 * 5 * 6 * 7;
  
  if (lenn + lenm > 7) {
    cout << 0 << endl;
    return;
  }

  set<string> ans;

  for (int i = 0; i < b; ++i) {
    if (good(s))
      ans.insert(s.substr(0, lenn + lenm));
    next_permutation(s.begin(), s.end());
  }


  cout << ans.size() << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}