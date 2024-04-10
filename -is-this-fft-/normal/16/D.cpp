#include <iostream>

using namespace std;

int get_time (string s) {
  int hr = 0;
  hr += s[1] - '0';
  hr *= 10;
  hr += s[2] - '0';

  int mn = 0;
  mn += s[4] - '0';
  mn *= 10;
  mn += s[5] - '0';

  bool is_pm = s[7] == 'p';
  if (is_pm) {
    if (hr != 12) {
      hr += 12;
    }
  } else {
    if (hr == 12) {
      hr -= 12;
    }
  }

  return hr * 60 + mn;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  string cur;
  getline(cin, cur);

  int ans = 1;
  pair<int, int> last = {0, 0};
  for (int i = 0; i < n; i++) {
    getline(cin, cur);
    int ti = get_time(cur);

    if (ti < last.first) {
      ans++;
      last = {ti, 1};
    } else if (ti == last.first) {
      last.second++;
      if (last.second > 10) {
        last.second -= 10;
        ans++;
      }
    } else {
      last = {ti, 1};
    }
  }

  cout << ans << '\n';
}