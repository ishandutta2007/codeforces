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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    int max1 = arr[0];
    int max2 = arr[1];
    if (max2 > max1)
      swap(max1, max2);
    for (int i = 2; i < n; i++) {
      int x = arr[i];
      if (x > max1) {
        max2 = max1;
        max1 = x;
      } else if (x > max2) {
        max2 = x;
      }
    }
    cout << min(max1 - 1, min(max2 - 1, n - 2)) << endl;
  }
  return 0;
}