#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll cnt [200];
ll cntp [200][200];

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  for (char c : s) {
    for (char a = 'a'; a <= 'z'; a++) {
      cntp[a][c] += cnt[a];
    }
    cnt[c]++;
  }

  ll ans = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    ans = max(ans, cnt[c]);
    for (char a = 'a'; a <= 'z'; a++) {
      ans = max(ans, cntp[a][c]);
    }
  }
  cout << ans << endl;
}