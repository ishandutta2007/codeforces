#include <bits/stdc++.h>
using namespace std;

string ans;
int freqs[256];

void use_one(char c) {
  ans.push_back(c);
  freqs[c]--;
}

void use_all(char c) {
  ans += string(freqs[c], c);
  freqs[c] = 0;
}

void finish() {
  for (char c = 'a'; c <= 'z'; c++) {
    use_all(c);
  }
  cout << ans << '\n';
  ans.clear();
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (char c: s) {
    freqs[c]++;
  }

  // f(t) = 0
  for (char c = 'a'; c <= 'z'; c++) {
    if (freqs[c] == 1) {
      use_one(c);
      finish();
      return;
    }
  }
  
  vector<char> usedchars;
  for (char c = 'a'; c <= 'z'; c++) {
    if (freqs[c]) usedchars.push_back(c);
  }
  
  // f(t) = 1
  if (freqs[usedchars[0]] <= n/2+1) {
    ans.resize(n, ' ');
    ans[0] = usedchars[0];
    for (int i = 1; i <= 2*freqs[usedchars[0]] - 3; i += 2) {
      ans[i] = usedchars[0];
    }
    freqs[usedchars[0]] = 0;
    int j = 1;
    for (int i = 0; i < n; i++) {
      if (ans[i] == ' ') {
        ans[i] = usedchars[j];
        if (!--freqs[usedchars[j]]) {
          j++;
        }
      }
    }
  }
  else if (usedchars.size() >= 3) {
    use_one(usedchars[0]);
    use_one(usedchars[1]);
    use_all(usedchars[0]);
    use_one(usedchars[2]);
  }
  else if (usedchars.size() == 2) {
    use_one(usedchars[0]);
    use_all(usedchars[1]);
  }

  finish();
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}