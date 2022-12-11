#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int nbTests;
  cin >> nbTests;

  for(int iTest = 0;iTest < nbTests;iTest++) {
    int a, b, n;
    cin >> a >> b >> n;

    if(n % 3 == 0)
      cout << a << endl;
    else if(n % 3 == 1)
      cout << b << endl;
    else
      cout << (a ^ b) << endl;
  }
  return 0;
}