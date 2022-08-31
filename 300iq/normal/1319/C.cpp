#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

bool dp[100][100][26];
bool good[100][100];
int best[101];

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool good = true;
  int ans = 0;
  while (good) {
    good = false;
    for (char c = 'z'; c >= 'a'; c--) {
      for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == c) {
          if ((i && s[i - 1] == c - 1) || (i +1  < (int) s.size() && s[i + 1] == c - 1)) {
            ans++;
            s.erase(s.begin() + i);
            good = true;
            break;
          }
        }
        if (good) break;
      }
    }
  }
  cout << ans << endl;
}