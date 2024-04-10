#include <iostream>
#include <string>

using namespace std;

int inx (char c) {
  if (c < 'a') {
    return (c - 'A' + 1);
  } else {
    return (c - 'a' + 1);
  }
}

int operate (char c) {
  bool at = '@' < c;
  bool brc = '[' > c;
  bool btc = '`' < c;
  bool cbr = '{' > c;

  bool up = at & brc;
  bool dn = btc & cbr;
  
  int iup = up * inx(c);
  int idn = dn * inx(c);

  return (iup - idn);
}

int main () {
  string s;
  cin >> s;
  
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += operate(s[i]);
  }

  cout << ans << endl;
}