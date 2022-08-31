#include <iostream>
#include <string>

using namespace std;

int marked [1000005];

int main () {
  int length;
  cin >> length;

  int ans = 0;
  string s, t;
  cin >> s >> t;

  for (int i = 0; i < length; i++) {
    if (s[i] != t[i]) {
      if (i != 0 && s[i - 1] != t[i - 1] && s[i - 1] != s[i] && !marked[i - 1]) {
        marked[i] = 1;
      } else {
        ans++;
      }
    }
  }

  cout << ans << endl;
}