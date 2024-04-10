#include <iostream>
#include <string>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  string str;
  cin >> str;

  int n = str.size();

  string ans = str;
  int ls = 0, ls1 = 0;
  int ds = 0, ds1 = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == '0') {
      ls++;
      ds++;
    } else {
      ls1++;
      ls = max(ls, ls1);

      if (ds + 1 > ls) {
        ds1++;
        ds = max(ds, ds1);
      } else {
        ds++;
        ans[i] = '0';
      }
    }
  }

  cout << ans << endl;
}