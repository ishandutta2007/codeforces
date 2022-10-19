#include <bits/stdc++.h>
using namespace std;

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
  vector<int> used(10);
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      int ind = 0;
      while (used[ind]) {
        ind++;
      }
      used[ind] = 1;
    } else if (s[i] == 'R') {
      int ind = 9;
      while (used[ind]) {
        ind--;
      }
      used[ind] = 1;
    } else {
      int ind = s[i] - '0';
      used[ind] = 0;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << used[i];
  }
  cout << endl;
  return 0;
}