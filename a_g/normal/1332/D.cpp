#include <bits/stdc++.h>
using namespace std;

const int B = 17;
const int z = 1<<B;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> k;
  cout << "2 3\n";
  cout << 2*z-1 << " " << z-1 << " " << z-1-k << '\n';
  cout << z << " " << 2*z-1 << " " << z-1 << '\n';
}