#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int diff[N];
long long diffsum[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      diff[a[j]-a[i]]++;
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; i+j < N; j++) {
      diffsum[i+j] += 1LL*diff[i]*diff[j];
    }
  }
  for (int i = 1; i < N; i++) diffsum[i] += diffsum[i-1];

  long long z = 0;
  for (int i = 1; i < N; i++) {
    z += diff[i]*diffsum[i-1];
  }
  int g = n*(n-1)/2;
  double ans = z;
  for (int i = 0; i < 3; i++) ans /= g;
  cout << ans << '\n';
}