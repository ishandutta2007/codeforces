#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200100;

ll c2[M];
ll a00, a01, a10, a11;

void pre() {
  for (int i = 0; i < M; ++i) {
    c2[i] = 1ll * i * (i - 1) / 2;
    assert(c2[i] >= 0);
  }
}

void read() {
  cin >> a00 >> a01 >> a10 >> a11;
}


void kill() {
  ll a = 0, b = 0;
  while (c2[a] < a00)
    ++a;
  while (c2[b] < a11)
    ++b;

  if (max(a01, a10) > 0) {
    a = max(1ll, a);
    b = max(1ll, b);
  }

  ll sum = a00 + a01 + a10 + a11;

  if (sum == 0) {
    cout << "1\n"; //MAMKU TVOYU EBAL
    //GORI V ADY
    //NO SPASIBO ZA PRETESTI
    return;
  }

  if (sum == 0 || c2[a] != a00 || c2[b] != a11 || sum != c2[a + b] || a01 > a * b || a10 > a * b) {
    cout << "Impossible\n";
    return;
  }

  assert(a01 + a10 == a * b);


  if (a == 0 || b == 0) {
    string ans = string(a, '0') + string(b, '1');
    cout << ans << endl;
    return;
  }

  int k = a01 / b;
  int r = a01 % b;

  string s;
  s += string(k, '0');
  s += string(b - r, '1');
  if (k < a)
    s += string(1, '0');
  s += string(r, '1');
  if (k + 1 < a)
    s += string(a - (k + 1), '0');

  cout << s << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  pre();
  read();
  kill();
}