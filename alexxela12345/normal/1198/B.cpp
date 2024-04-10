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
  int q;
  cin >> q;
  vector<pair<int, int>> upd;
  vector<int> kek;
  vector<int> last_upd(n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      upd.push_back({p, x});
    } else {
      int x;
      cin >> x;
      for (pair<int, int> el : upd) {
        int pp = el.first;
        last_upd[pp - 1] = kek.size() + 1;
        int xx = el.second;
        xx = max(xx, x);
        arr[pp - 1] = xx;
      }
      kek.push_back(x);
      upd.clear();
    }
  }
  for (pair<int, int> el : upd) {
    int pp = el.first;
    last_upd[pp - 1] = kek.size() + 1;
    int xx = el.second;
    arr[pp - 1] = xx;
  }
  for (int i = kek.size() - 2; i >= 0; i--) {
    kek[i] = max(kek[i], kek[i + 1]);
  }
  for (int i = 0; i < n; i++) {
    if (last_upd[i] < kek.size())
      arr[i] = max(arr[i], kek[last_upd[i]]);
  }
  cout << arr << endl;
  return 0;
}