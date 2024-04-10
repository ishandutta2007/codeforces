#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a < b) ? b : a

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (auto &el : arr) {
    in >> el;
  }
  return in;
}

template<typename T1, typename T2> 
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
  for (auto &el : arr) {
    out << el;
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> arr(n, vector<int> (2));
  int cur = 0;
  while (q--) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    swap(r, c);  
    int cnt = 0;
    if (c == 0) {
      cnt += arr[r][1];
      if (r)
        cnt += arr[r - 1][1];
      if (r != n - 1)
        cnt += arr[r + 1][1];
    } else {
      cnt += arr[r][0];
      if (r)
        cnt += arr[r - 1][0];
      if (r != n - 1)
        cnt += arr[r + 1][0];
    }
    if (arr[r][c] == 1) {
      cnt *= -1;
    }
    arr[r][c] = 1 - arr[r][c];
    cur += cnt;
    if (cur) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}