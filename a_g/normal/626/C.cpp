#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int low = 0;
  int high = 5e6;
  while (high-low > 1) {
    int mid = (low+high)/2;
    int c2 = mid/2;
    int c3 = mid/3;
    int c6 = mid/6;
    if (c6 >= n-min(n, c2-c6)+m-min(m, c3-c6)) high = mid;
    else low = mid;
  }
  cout << high << '\n';
}