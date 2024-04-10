#include <iostream>

using namespace std;

int main () {
  int n, K;
  cin >> n >> K;

  int l = 1, r = K + 1;
  while (true) {
    cout << l << " ";
    if (r == l) break;
    cout << r << " ";
    l++;
    r--;
    if (r < l) break;
  }
  
  for (int i = K + 2; i <= n; i++) {
    cout << i << " ";
  }
  cout << endl;
}