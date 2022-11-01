#include <bits/stdc++.h>

using namespace std;

set <string> s;
int n;
string x;

int main() {
  cin >> n;
  while (n--) {
    cin >> x;
    if (s.count(x)) puts("YES");
    else puts("NO");
    s.insert(x);
  }
  return 0;
}