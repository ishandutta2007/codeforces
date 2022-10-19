#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

template<typename T1, typename T2>
istream& operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

template<typename T>
istream& operator>>(istream& in, vector<T> &vec) {
  for (auto &el : vec) {
    in >> el;
  }
  return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T> &vec) {
  for (auto &el : vec) {
    out << el << " ";
  }
  return out;
}

ll gcd(ll a, ll b) {
  while (b) {
    ll tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef LOCAL
  cout << "Running local" << endl;
#endif
  ll n, m;
  int q;
  cin >> n >> m >> q;
  ll gg = gcd(n, m);
  while (q--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll s1, s2;
    if (a == 1) {
      s1 = (b - 1) / (n / gg);
    } else {
      s1 = (b - 1) / (m / gg);
    }
    if (c == 1) {
      s2 = (d - 1) / (n / gg);
    } else {
      s2 = (d - 1) / (m / gg);
    }
    if (s1 == s2) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}