#include <iostream>
#include <string>

using namespace std;

const int maxn = 1005;

int ans [maxn];

int main () {
  string s;
  cin >> s;

  int n = s.size();
  
  s += 'b';

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != s[i + 1]) {
      ans[i] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}