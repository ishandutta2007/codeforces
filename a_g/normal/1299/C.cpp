#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+2;
long long a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }
  vector<int> pts = {0};
  for (int i = 1; i <= n; i++) {
    int m = pts.size();
    while (m > 1 && a[pts[m-2]]*pts[m-1] + a[pts[m-1]]*i + a[i]*pts[m-2] >= a[pts[m-2]]*i + a[pts[m-1]]*pts[m-2] + a[i]*pts[m-1]) {
      pts.pop_back();
      m--;
    }
    pts.push_back(i);
  }
  int m = pts.size();
  for (int i = 0; i < m-1; i++) {
    int count = pts[i+1]-pts[i];
    double avg = (double)(a[pts[i+1]]-a[pts[i]])/(count);
    while (count--) {
      cout << avg << '\n';
    }
  }
}