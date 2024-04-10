/*#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif*/
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
    out << el << " ";
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
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "! 1" << endl;
    return 0;
  }
  vector<int> used(n);
  vector<int> arr(n);
  int cntKnow = 0;
  int lastVal = INT_MIN;
  vector<int> lastq;
  while (true) {
    vector<int> unused;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        unused.push_back(i);
        if ((int) unused.size() == k) {
          break;
        }
      }
    }
    if ((int) unused.size() < k) {
      break;
    }
    cntKnow++;
    cout << "?";
    for (int el : unused) {
      cout << " " << el + 1;
    }
    lastq = unused;
    cout << endl;
    int ind, val;
    cin >> ind >> val;
    lastVal = val;
    ind--;
    used[ind] = 1;
    arr[ind] = val;
  }
  if (cntKnow >= k) {
    vector<int> inds;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        inds.push_back(i);
        vals.push_back(arr[i]);
        if ((int) inds.size() == k)
          break;
      }
    }
    sort(vals.begin(), vals.end());
    cout << "?";
    for (int el : inds) {
      cout << " " << el + 1;
    }
    cout << endl;
    int ind, val;
    cin >> ind >> val;
    for (int i = 0; i < k; i++) {
      if (vals[i] == val) {
        cout << "! ";
        cout << i + 1 << endl;
        return 0;
      }
    }
    cout << "AAAAA" << endl;
    cout << vals << endl;
    cout << arr << endl;
    return 0;
  }
  vector<int> inds = lastq;
  for (int i = 0; i < (int) inds.size(); i++) {
    if (used[inds[i]]) {
      swap(inds[0], inds[i]); 
    }
  }
  int cntSmall = 0;
  int other = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (used[i] && i != inds[0]) {
      other = i;
    }
  }
  for (int i = 1; i < (int) inds.size(); i++) {
    int kek = inds[i];
    inds[i] = other;
    cout << "?";
    for (int el : inds) {
      cout << " " << el + 1;
    }
    cout << endl;
    int indd, vall;
    cin >> indd >> vall;
    if (vall == lastVal) {
      if (arr[other] < arr[inds[0]])
        cntSmall++;
    } else {
      if (arr[other] > arr[inds[0]]) {
        cntSmall++;
      }
    }
    inds[i] = kek;
  }
  cout << "! " << cntSmall + 1 << endl;
}