#ifdef LOCAL
#define _GLIBCXX_DEBUG
#else
#pragma GCC optimize("Ofast,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,popcnt")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define endl '\n'
#endif
#define int long long

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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef LOCAL
  cout << "Running local" << endl;
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> arr(n);
  cin >> arr;
  int bans = 0;
  for (int i = 0; i < m; i++) {
    vector<int> prefix(n + 1);
    for (int j = i + 1; j <= n; j++) {
      prefix[j] = prefix[j - 1] + arr[j - 1];
    }
    for (int j = 0; j <= n; j++) {
      prefix[j] -= (j - i + m - 1) / m * k;
    }
    int ans = 0;
    int minn = 0;
    for (int j = i; j < n; j++) {
      if (j % m == i)
        minn = min(minn, prefix[j]);
      ans = max(ans, prefix[j + 1]- minn);
    }
    bans = max(ans, bans);
  }
  cout << bans << endl;
  return 0;
}