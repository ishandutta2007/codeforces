#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;

int n;
string s;
bool remove() {
  int pos = -1;
  char c = 0;
  for (int i = 0; i < n; i++) {
    if ((i && s[i] == s[i - 1] + 1) || (i < n - 1 && s[i] == s[i + 1] + 1)) {
      if (s[i] > c) {
        c = s[i];
        pos = i;
      }
    }
  }
  if (~pos) {
    s.erase(pos, 1);
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> s;
  int ans = 0;
  for (int i = 1; i < n; i++) ans += remove();
  cout << ans << endl;
  return 0;
}