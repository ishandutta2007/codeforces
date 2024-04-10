#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bests (string s, int n) {
  vector<int> cnt (200, 0);
  for (char c : s) {
    cnt[c]++;
  }

  int mx = 0;
  for (int i = 0; i < 200; i++) {
    mx = max(mx, cnt[i]);
  }

  if (n == 0) return mx;
  if (mx == s.size() && n < (int) s.size() && n == 1) return mx - 1;
  
  return min((int) s.size(), mx + n);
}

int main () {
  int n;
  cin >> n;

  string a, b, c;
  cin >> a >> b >> c;

  int as = bests(a, n);
  int bs = bests(b, n);
  int cs = bests(c, n);
  cerr <<as << bs << cs << endl;
  
  if (as > bs && as > cs) {
    cout << "Kuro" << endl;
  } else if (bs > as && bs > cs) {
    cout << "Shiro" << endl;
  } else if (cs > as && cs > bs) {
    cout << "Katie" << endl;
  } else {
    cout << "Draw" << endl;
  }
}