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
  int n;
  cin >> n;
  vector<int> arr(n);
  cin >> arr;
  vector<int> ans(n);
  for (int i = 0; i < 30; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j] & (1 << i)) {
        cnt++;
      }
    }
    if (cnt == 1) {
      for (int j = 0; j < n; j++) {
        if (arr[j] & (1 << i)) {
          ans[j] += (1 << i);
        }
      }
    }
  }
  int ind = max_element(ans.begin(), ans.end()) - ans.begin();
  cout << arr[ind] << " ";
  for (int i = 0; i < n; i++) {
    if (i != ind) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;
}