#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cin >> b[i];
    }
    int low = 1;
    int high = n+1;
    while (low+1 < high) {
      int mid = (low+high)/2;
      //try to invite mid people
      int index = 0;
      for (int i = 0; i < n; i++) {
        if (index >= mid) break;
        if (a[i] >= mid-1-index && b[i] >= index) index++;
      }
      if (index >= mid) low = mid;
      else high = mid;
    }
    cout << low << endl;
  }
}