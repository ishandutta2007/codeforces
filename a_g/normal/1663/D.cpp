#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  int x;
  cin >> s >> x;
  bool rated = 1;
  if (s == "ABC" && x >= 2000) rated = 0;
  if (s == "ARC" && x >= 2800) rated = 0;
  if (s == "AGC" && x < 1200) rated = 0;
  cout << (rated ? "YES" : "NO") << '\n';
}