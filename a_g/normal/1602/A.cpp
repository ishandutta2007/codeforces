#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    auto minchar = min_element(s.begin(), s.end());
    cout << *minchar << " ";
    s.erase(minchar);
    cout << s << endl;
  }
}