#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int mx = 0;
    for (char c : s) {
      mx = max(mx, (int) c - '0');
    }
    cout << mx << '\n';
  }
}