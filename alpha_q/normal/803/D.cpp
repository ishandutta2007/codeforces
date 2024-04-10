#include <bits/stdc++.h> 

using namespace std;

const int N = 1000010;

int k, p; 
string s;
int a[N];

bool ok (int x) {
  for (int i = 1; i <= p; ++i) {
    if (a[i] > x) return 0;
  }
  int tot = 1;
  for (int i = 1, sum = 0; i <= p; ++i) {
    if (sum + a[i] <= x) {
      sum += a[i];
    } else {
      ++tot;
      sum = a[i];
    }
  }
  return tot <= k;
}

int main (int argc, char const *argv[]) {
  cin >> k;
  getline(cin, s);
  getline(cin, s);
  s += '-';
  for (int i = 0, j = 0; i < s.size(); ++i) {
    if (s[i] == ' ' or s[i] == '-') {
      a[++p] = i - j + 1;
      j = i + 1;
    }
  }
  --a[p];
  int lo = 0, hi = N; 
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  cout << lo << endl;
  return 0;
}