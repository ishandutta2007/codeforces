#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;

int rgend [MAX_N];
int cost [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.size();
  pair<int, int> ans = make_pair(0, 0);
  for (int i = n - 1; i >= 0; i--) {
    rgend[i] = -1;
    cost[i] = 0;
    if (s[i] == '(') {
      if (i != n - 1 && s[i + 1] == ')') {
        rgend[i] = i + 1;
      } else if (i != n - 1 &&
                 rgend[i + 1] != -1 &&
                 rgend[i + 1] != n - 1 &&
                 s[rgend[i + 1] + 1] == ')') {
        rgend[i] = rgend[i + 1] + 1;
        cost[i] += cost[i + 1];
      }
    }

    if (s[i] == '[') {
      if (i != n - 1 && s[i + 1] == ']') {
        rgend[i] = i + 1;
        cost[i]++;
      } else if (i != n - 1 &&
                 rgend[i + 1] != -1 &&
                 rgend[i + 1] != n - 1 &&
                 s[rgend[i + 1] + 1] == ']') {
        rgend[i] = rgend[i + 1] + 1;
        cost[i] += cost[i + 1] + 1;
      }
    }

    if (rgend[i] != -1 &&
        rgend[i] != n - 1 &&
        rgend[rgend[i] + 1] != -1) {
      cost[i] += cost[rgend[i] + 1];
      rgend[i] = rgend[rgend[i] + 1];
    }

    if (rgend[i] != -1) {
      ans = max(ans, make_pair(cost[i], i));
    }
  }

  cout << ans.first << '\n';
  if (ans.first != 0) {
    for (int i = ans.second; i <= rgend[ans.second]; i++) {
      cout << s[i];
    }
  }
  cout << '\n';
}