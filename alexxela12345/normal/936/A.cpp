#ifdef LOCAL
#define _GLIBCXX_DEBUG
#else
//#pragma GCC optimize("Ofast,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define endl '\n'
#endif

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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef LOCAL
  cout << "Running local" << endl;
#endif
  
  ldb k, d, t;
  cin >> k >> d >> t;
  d = d * floor((k + d - 1) / d);
  ldb kek = (ldb) k / t + (ldb) (d - k) / (2 * t);
  ll cnt = (ll) (1.0 / kek);
  ldb ans = cnt * d;
  ldb l = (ldb) 1 - cnt * kek; 
  if (l <= (ldb) k / t) {
    ans += l * t;
  } else {
    l -= (ldb) k / t;
    ans += k;
    ans += l * 2 * t;
  }
  cout.precision(20);
  cout << ans << endl;
  return 0;
}