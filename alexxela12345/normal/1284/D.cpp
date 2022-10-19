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

struct ev {
  int t, u, i;

  ev(int t, int u, int i) : t(t), u(u), i(i) {}

  bool operator<(const ev &other) const {
    if (t != other.t)
      return t < other.t;
    return u < other.u;
  }
};

void check(vector<pair<pair<int, int>, pair<int, int>>> arr) {
  sort(arr.begin(), arr.end());
  int n = arr.size();
  vector<ev> evs;
  for (int i = 0; i < n; i++) {
    evs.push_back(ev(arr[i].first.first, 0, i));
    evs.push_back(ev(arr[i].first.second, 1, i));
  }
  sort(evs.begin(), evs.end());
  multiset<int> starts, ens;
  for (int i = 0; i < (int) evs.size(); i++) {
    int tt = evs[i].u;
    int ind = evs[i].i;
    if (tt == 0) {
      int a = arr[ind].second.first;
      int b = arr[ind].second.second;
      if (!starts.empty() && ((*starts.rbegin() > b) || (*ens.begin() < a))) {
        cout << "NO" << endl;
        exit(0);
      }
      starts.insert(a);
      ens.insert(b);
    } else {
      starts.erase(starts.find(arr[ind].second.first));
      ens.erase(ens.find(arr[ind].second.second));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<pair<int, int>, pair<int, int>>> arr(n);
  cin >> arr;
  check(arr);
  for (int i = 0; i < n; i++) {
    swap(arr[i].first, arr[i].second);
  }
  check(arr);
  cout << "YES" << endl;
}