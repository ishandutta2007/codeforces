#include <bits/stdc++.h>

using namespace std;

string s;
int a, b;

int main() {
  cin >> s;
  for (char c : s) {
    if (c == '-') ++a;
    else ++b;
  }
  puts((b == 0 or a % b == 0) ? "YES" : "NO");
  return 0;
}