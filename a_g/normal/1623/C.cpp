#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+2;
ll h[N];
ll c[N];
int n;

bool check2(int k) {
  for (int i = 0; i < n; i++) {
    c[i] = h[i];
  }
  for (int i = n-1; i >= 2; i--) {
    if (c[i] < k) return 0;
    ll x = min((c[i]-k), h[i])/3;
    c[i] -= 3*x;
    c[i-1] += x;
    c[i-2] += 2*x;
  }
  if (c[1] < k || c[0] < k) return 0;
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    int low = 0;
    int high = 1e9+5;
    while (low + 1 < high) {
      int mid = (low+high)/2;
      if (check2(mid)) low = mid;
      else high = mid;
    }
    cout << low << '\n';
  }
}