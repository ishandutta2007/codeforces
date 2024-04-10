#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string a;
    cin >> n >> a;
    sort(a.begin(), a.end());
    cout << a << endl;
  }
}