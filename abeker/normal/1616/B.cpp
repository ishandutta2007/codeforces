#include <bits/stdc++.h>
using namespace std;

string s;

void output(int k) {
  s.resize(k);
  cout << s;
  reverse(s.begin(), s.end());
  cout << s << endl;
}

void solve() {
  int N;
  cin >> N >> s;
  if (N == 1 || s[0] <= s[1]) {
    output(1);
    return;
  }
  for (int i = 1; i < N - 1; i++)
    if (s[i + 1] > s[i]) {
      output(i + 1);
      return;
    }
  output(N);
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}