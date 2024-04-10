#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

int n, t;
string s;

void read() {
  cin >> n >> t;
  cin >> s;
  n = s.length();
}


void kill() {
  int i = 0;
  while (s[i] != '.')
    ++i;
  ++i;
  while (i < n && s[i] < '5')
    ++i;

  if (i == n) {
    cout << s << endl;
    return;
  }


  while (t > 0) {
    --i;
    bool dot = s[i] == '.';

    if (dot)
      --i;

    s[i] += 1;

    if (s[i] == '9' + 1) {
      s[i] -= 1;
      assert(dot);

      vector<int> ans;

      int cur = 1;
      for (int j = i; j >= 0 || cur > 0; --j) {

        if (j >= 0)
          cur += s[j] - '0';

        ans.push_back(cur % 10);
        cur /= 10;
      }

      reverse(ans.begin(), ans.end());
      for (int x : ans)
        cout << x;
      cout << endl;
      return;
    }

    --t;

    if (s[i] < '5' || dot)
      break;
  }


  cout << s.substr(0, i + 1) << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}