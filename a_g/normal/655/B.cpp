#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  k = min(k, n/2);
  cout << 1LL*k*(2*n-2*k-1) << endl;
}