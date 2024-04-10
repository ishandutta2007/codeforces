#include <iostream>
#include <string>

const int ALPHA = 128;

using namespace std;

bool vis [ALPHA];

int main () {
  int strl;
  cin >> strl;
  
  if (strl >= 27) {
    cout << -1 << endl;
    return 0;
  }

  string base;
  cin >> base;
  int ans = 0;
  for (int i = 0; i < strl; i++) {
    if (vis[base[i]]) {
      ans++;
    }

    vis[base[i]] = true;
  }

  cout << ans << endl;
}