#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int cur [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  ll x, y;
  cin >> x >> y;

  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cur[i] = 1;
    } else {
      cur[i] = 0;
    }
  }

  ll curscore = 0;
  ll c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    if (cur[i] == 1) {
      curscore += x * c0;
      c1++;
    } else {
      curscore += y * c1;
      c0++;
    }
  }

  ll ans = curscore;
  if (y - x < 0) {
    // blanks should be 111...000
    ll c0l = 0, c0r = c0;
    ll c1l = 0, c1r = c1;
    for (int i = 0; i < n; i++) {
      if (cur[i] == 0) {
        c0r--;
      } else {
        c1r--;
      }
      
      if (s[i] == '?') {
        curscore -= x * c1r;
        curscore -= y * c1l;
        
        curscore += x * c0l;
        curscore += y * c0r;
        ans = min(ans, curscore);
        cur[i] = 1;
      }

      if (cur[i] == 0) {
        c0l++;
      } else {
        c1l++;
      }
    }
  } else {
    // blanks should be 000...111

    ll c0l = 0, c0r = c0;
    ll c1l = 0, c1r = c1;
    for (int i = n - 1; i >= 0; i--) {
      if (cur[i] == 0) {
        c0r--;
      } else {
        c1r--;
      }
      
      if (s[i] == '?') {
        curscore -= x * c1l;
        curscore -= y * c1r;

        curscore += y * c0l;
        curscore += x * c0r;
        ans = min(ans, curscore);
        cur[i] = 1;
      }

      if (cur[i] == 0) {
        c0l++;
      } else {
        c1l++;
      }
    }
  }

  cout << ans << endl;
}