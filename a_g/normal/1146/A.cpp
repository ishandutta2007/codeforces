#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  int a = count(s.begin(), s.end(), 'a');
  cout << min(n, 2*a-1) << '\n';
}