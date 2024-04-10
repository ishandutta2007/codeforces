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
  int m;
  cin >> m;
  m *= 8;
  vector<int> arr(n);
  cin >> arr;
  int k = 0;
  long long cur_n = 1;
  while ((k + 1) * n <= m && cur_n < 10000000000LL) {
    k++;
    cur_n *= 2;
  }
  sort(arr.begin(), arr.end());
  int r = -1;
  set<int> s;
  map<int, int> cnt;
  int ans = n;
  for (int l = 0; l < n; l++) {
    if (r == l - 1) {
      s.insert(arr[l]);
      cnt[arr[l]]++;
      r = l;
    }
    while (r < n - 1) {
      s.insert(arr[++r]);
      cnt[arr[r]]++;
      if (s.size() > cur_n) {
        cnt[arr[r]]--;
        s.erase(arr[r]);
        r--;
        break;
      }
    }
    ans = min(ans, n - (r - l + 1));
    cnt[arr[l]]--;
    if (cnt[arr[l]] == 0) {
      s.erase(arr[l]);
    }
  } 
  cout << ans << endl;
  return 0;
}