#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

string s;

void read() {
  cin >> s;
}


void kill() {
  int l = 0;
  int n = s.length();
  while (l < n && s[l] == 'a')
    ++l;
  int r = l;
  while (r < n && s[r] != 'a')
    ++r;
  if (l < r) {
    for (int i = l; i < r; ++i)
      s[i] -= 1;
    cout << s << endl;
    return;
  }
  s[n - 1] = 'z';
  cout << s << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}