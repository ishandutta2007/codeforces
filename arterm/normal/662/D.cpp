#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define stoi adsfjasd

const int M = 11;
ll pw[M];

ll stoi(string s) {
  ll ans = 0;
  for (char c : s)
    ans = 10 * ans + (c - '0');
  return ans;
}

ll concat(ll x, string tail) {
  if (x == 0 && tail[0] == '0')
    return -1;
  return x * pw[tail.length()] + stoi(tail);
}

ll first(ll mn, string tail) {
  ll val = stoi(tail);
  if (tail[0] != '0' && val >= mn)
    return val;

  ll p = pw[tail.length()];
  ll x = (mn - val + p - 1) / p;
  return x * p + val;
}

ll find(string s) {
  ll mn = 1988;
  for (int i = 1; i <= (int) s.length(); ++i) {
    mn = first(mn + 1, s.substr(s.length() - i, i));
  }
  return mn;
}

void read() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    s = s.substr(4, s.length() - 4);
    cout << find(s) << "\n";
  }
}


int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  pw[0] = 1;
  for (int i = 1; i < M; ++i)
    pw[i] = 10 * pw[i - 1];
  read();
}