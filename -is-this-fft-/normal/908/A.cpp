#include <iostream>
#include <string>

using namespace std;

int main () {
  string st;
  cin >> st;

  int ans = 0;
  for (char c : st) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == '1' || c == '3' || c == '5' || c == '7' || c == '9') {
      ans++;
    }
  }

  cout << ans << endl;
}