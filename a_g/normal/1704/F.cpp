#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int dp[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < 200; i++) {
    set<int> seen;
    for (int j = 0; j <= i-2; j++) {
      seen.insert(dp[j]^dp[i-2-j]);
    }
    while (seen.count(dp[i])) dp[i]++;
  }
   for (int i = 200; i < N; i++) dp[i] = dp[i-34];

  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int r = count(s.begin(), s.end(), 'R');
    int b = count(s.begin(), s.end(), 'B');
    if (r != b) {
      cout << (r > b ? "Alice" : "Bob") << '\n';
      continue;
    }
    int nim = 0;
    auto eval = [&] (string& t) {
      int k = t.size();
      nim ^= dp[k];
    };

    string piece;
    for (char c: s) {
      if (!piece.size() || piece.back() != c) {
        piece.push_back(c);
      }
      else {
        eval(piece);
        piece = c;
      }
    }
    eval(piece);
    cout << (nim ? "Alice" : "Bob") << '\n';
  }
}