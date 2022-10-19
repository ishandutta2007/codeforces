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

bool in(int a, int b, int c, int d) {
  return c <= a && b <= d;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef LOCAL
  cout << "Running local" << endl;
#endif
  int n, k;
  cin >> n >> k;
  vector<string> arr(n);
  cin >> arr;
  vector<int> fc(n, -1), fr(n, -1);
  vector<int> lc(n, -1), lr(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 'B') {
        lr[i] = j;
        lc[j] = i;
      }
      if (arr[i][n - 1 - j] == 'B') {
        fr[i] = n - 1 - j;
      }
      if (arr[n - 1 - i][j] == 'B') {
        fc[j] = n - 1 - i;
      }
    }
  }
  int cnt1 = 0;
  for (int i = 0; i < n; i++) {
    if (fr[i] == -1)
      cnt1++;
    if (fc[i] == -1)
      cnt1++;
  }
  vector<vector<int>> arr2(n + 1, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (in(fr[i], lr[i], j, j + k - 1)) {
        arr2[i + 1][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      arr2[i][j] += arr2[i - 1][j];
    }
  }
  int max_cnt = 0;
  for (int i = 0; i < n - k + 1; i++) {
    int cur_cnt = 0;
    for (int j = 0; j < k; j++) {
      if (in(fc[j], lc[j], i, i + k - 1)) {
        cur_cnt++;
      }
    }
    max_cnt = max(max_cnt, cur_cnt + arr2[i + k][0] - arr2[i][0]);
    for (int j = 1; j < n - k + 1; j++) {
      if (in(fc[j - 1], lc[j - 1], i, i + k - 1)) {
        cur_cnt--;
      }
      if (in(fc[j - 1 + k], lc[j - 1 + k], i, i + k - 1)) {
        cur_cnt++;
      }
      max_cnt = max(max_cnt, cur_cnt + arr2[i + k][j] - arr2[i][j]);
    }
  }
  cout << cnt1 + max_cnt;
  cout << endl;
  return 0;
}