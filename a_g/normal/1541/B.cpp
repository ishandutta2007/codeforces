#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      int start = (a[i] - i-1) % a[i];
      if (start < 0) start += a[i];
      for (int j = start-1; j < n; j+= a[i]) {
        if (j > i && a[i]*a[j] == i+j+2) count++;
      }
    }
    cout << count << endl;
  }
}