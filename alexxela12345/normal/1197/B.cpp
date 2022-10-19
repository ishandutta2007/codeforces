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
  int n;
  cin >> n;
  vector<int> arr(n);
  cin >> arr;
  int ind = max_element(arr.begin(), arr.end()) - arr.begin();
  int l = ind - 1;
  int r = ind + 1;
  while (l != -1 || r != n) {
    if (l != -1 && arr[l] > arr[ind]) {
      cout << "NO" << endl;
      return 0;
    }
    if (r != n && arr[r] > arr[ind]) {
      cout << "NO" << endl;
      return 0;
    }
    if (l == -1) {
      arr[ind] = arr[r++];
    } else if (r == n) {
      arr[ind] = arr[l--];
    } else if (arr[l] < arr[r]) {
      arr[ind] = arr[r++];
    } else {
      arr[ind] = arr[l--];
    }
  }
  cout << "YES" << endl;
  return 0;
}