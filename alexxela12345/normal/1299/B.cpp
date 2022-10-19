#ifndef LOCAL
//#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long

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

struct vec {
  int x, y;
  vec(int x, int y) : x(x), y(y) {}

  bool operator==(const vec &a) const {
    return x == a.x && y == a.y;
  }
};

int cross(vec a, vec b) {
  return a.x * b.y - a.y * b.x;
}

bool cmp(vec a, vec b) {
  return cross(a, b) > 0;
}

vector<vec> norm(vector<vec> a) {
  int ind = 0;
  vector<vec> ans;
  for (int i = 1; i < (int) a.size(); i++) {
    if (tie(a[ind].x, a[ind].y) > tie(a[i].x, a[i].y)) {
      ind = i;
    }
  }
  ans.push_back(vec(0, 0));
  for (int i = ind + 1; i % (int) a.size() != ind; i++) {
    auto kek = a[i % a.size()];
    ans.push_back(vec(kek.x - a[ind].x, kek.y - a[ind].y));
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vec> a, b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(vec(x, y));
    b.push_back(vec(-x, -y));
  }
  a = norm(a);
  b = norm(b);
  if (a == b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}