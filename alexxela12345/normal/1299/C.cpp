#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

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
    out << el << endl;
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

struct pt {
  int x, y;
  int ind;
  pt(int x, int y, int ind) : x(x), y(y), ind(ind) {}
};

int cross(pt a, pt b) {
  return a.x * b.y - a.y * b.x;
}

vector<pt> pts;

pt sub(pt a, pt b) {
  return pt(a.x - b.x, a.y - b.y, -1);
}

void add(int x, int y, int ind) {
  pt p(x, y, ind);
  while (pts.size() >= 2 && cross(sub(pts.back(), p), sub(pts[pts.size() - 2], pts.back())) < 0) {
    pts.pop_back();
  }
  pts.push_back(p);
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  cin >> arr;
  vector<int> dp(n);
  vector<int> pref(n + 1);
  for (int i = 1; i < n + 1; i++) {
    pref[i] = pref[i - 1] + arr[i - 1];
  }
  add(n, pref[n], n - 1);
  for (int i = n - 1; i >= 0; i--) {
    add(i, pref[i], i - 1);
    dp[i] = pts[pts.size() - 2].ind;
  }
  int cur = 0;
  vector<long double> ans;
  ans.reserve(n);
  while (cur < n) {
    int lst = dp[cur];
    long double sm = 0;
    for (int i = cur; i <= lst; i++) {
      sm += arr[i];
    }
    sm /= lst - cur + 1;
    for (int i = cur; i <= lst; i++) {
      ans.push_back(sm);
    }
    cur = lst + 1;
  }
  cout.precision(20);
  cout << ans << endl;
}