#include <iostream>

using namespace std;

int blog (int num) {
  int ans = 0;
  while (num != 0) {
    ans++;
    num /= 2;
  }
  return ans;
}

int main () {
  int n;
  cin >> n;
  cout << blog(n) << endl;
}