#include <iostream>

using namespace std;

int main () {
  int length, sublen;
  cin >> length >> sublen;

  int period = (length - sublen) / 2 + 1;
  string ans;
  for (int i = 1; i <= length; i++) {
    if (i % period == 0) {
      ans += '0';
    } else {
      ans += '1';
    }
  }

  cout << ans << '\n';
}