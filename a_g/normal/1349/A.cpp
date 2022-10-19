#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b;

void f() {
  ll x = __gcd(a, b);
  ll y = a*b/x;
  a = x;
  b = y;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  cin >> a;
  cin >> b;
  f();
  while (n-->2) { // n goes to 2 :)
    ll c;
    cin >> c;
    b = __gcd(b, c);
    f();
  }
  cout << b << endl;
}