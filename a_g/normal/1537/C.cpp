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
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll d = 1e10;
    for (int i = 0; i < n-1; i++) {
      d = min<ll>(d, h[i+1]-h[i]);
    }
    for (int i = 0; i < n-1; i++) {
      if (h[i+1]-h[i] == d) {
        cout << h[i] << " ";
        for (int j = i+2; j < n; j++) {
          cout << h[j] << " ";
        }
        for (int j = 0; j < i; j++) {
          cout << h[j] << " ";
        }
        cout << h[i+1] << endl;
        break;
      }
    }
  }
}