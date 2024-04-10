#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;

int n;
string s;

void read() {
  cin >> n >> s;
}

void kill() {
  int l = 0;
  while (l < n && s[l] == '<')
    ++l;
  int r = n - 1;
  while (r >= 0 && s[r] == '>')
    --r;

  int ans = l + (n - 1 - r);
  cout << ans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}