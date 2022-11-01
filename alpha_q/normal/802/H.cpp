#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  int ptr = 0;
  string s = "", p = "";
  while (n > 1) {
    --n;
    if (n & 1) {
      s += char('A' + ptr);
      p += char('A' + ptr);
      ptr++;
      if (ptr == 26) ptr = 'a' - 'A';
    } else {
      s += char('A' + ptr);
      s += char('A' + ptr);
      p += char('A' + ptr);
      ptr++, n >>= 1;
      if (ptr == 26) ptr = 'a' - 'A';
    }
  }
  s += p;
  if (p.empty()) s = p = "a";
  cout << s << " " << p << '\n';
  return 0;
}