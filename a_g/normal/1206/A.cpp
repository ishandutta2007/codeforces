#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  int a = 0;
  int b = 0;
  cin >> n;
  int val;
  while(n--) {
    cin >> val;
    a = max(a, val);
  }
  cin >> m;
  while(m--) {
    cin >> val;
    b = max(b, val);
  }
  cout << a << " " << b << endl;

}