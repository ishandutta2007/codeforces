#include <bits/stdc++.h> 

using namespace std;

int n, l;
string s[60];
string t[60];

int main (int argc, char const *argv[]) {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    t[i] = s[i] + s[i];
  }
  l = s[0].size();
  int flag = 1;
  for (int i = 1; i < n; ++i) {
    int works = 0;
    for (int j = 0; j < l; ++j) {
      if (t[i].substr(j, l) == s[0]) {
        works = 1;
        break;
      }
    }
    if (works == 0) {
      flag = 0;
      break;
    }
  }
  if (flag == 0) {
    puts("-1");
    return 0;
  }
  int ans = 1000 * 1000 * 1000;
  for (int i = 0; i < l; ++i) {
    string target = t[0].substr(i, l);
    int tot = 0;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < l; ++k) {
        if (t[j].substr(k, l) == target) {
          tot += k;
          break;
        }
      }
    }
    ans = min(ans, tot);
  }
  cout << ans << endl;
  return 0;
}