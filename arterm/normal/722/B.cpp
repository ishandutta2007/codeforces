#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

int n;
int p[M];
string s[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  getline(cin, s[0], '\n');
  for (int i = 0; i < n; ++i) {
    getline(cin, s[i], '\n');
    //cout << "s[i] = " << s[i] << "!!\n";
  }
}

bool vowel(char ch) {
  for (char c : {'a', 'e', 'i', 'o', 'u', 'y'})
    if (ch == c)
      return true;
  return false;
}

void kill() {
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (char c : s[i])
      if (vowel(c))
        ++cnt;
    if (cnt != p[i]) {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << "YES\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}