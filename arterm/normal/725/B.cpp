#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int B = 16;
const int bon[] = {0, 7, 0, 7};
map<char, int> cnt;

void pre() {
  cnt['f'] = 0;
  cnt['e'] = 1;
  cnt['d'] = 2;

  cnt['a'] = 3;
  cnt['b'] = 4;
  cnt['c'] = 5;
}

ll n;
char c;

void read() {
  string in;
  cin >> in;
  
  int len = in.length();
  c = in[len - 1];

  in = in.substr(0, len - 1);

  n = 0;
  for (char c : in) {
    n = 10l * n + (c - '0');
  }

  n--;
}


void kill() {
  ll ans = (n / 4) * B;
  n %= 4;
  ans += bon[n];
  ans += cnt[c];
  ans += 1;
  cout << ans << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  pre();
  read();
  kill();
}