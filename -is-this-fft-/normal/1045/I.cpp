#include <iostream>
#include <string>
#include <map>

using namespace std;

int bitify (string s) {
  int ans = 0;
  for (char c : s) {
    ans ^= 1 << (c - 'a');
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  int strc;
  cin >> strc;

  long long ans = 0;
  map<int, int> cnt;
  for (int i = 0; i < strc; i++) {
    string s;
    cin >> s;

    int bm = bitify(s);
    if (cnt.count(bm) == 0) {
      cnt[bm] = 0;
    }
    ans += cnt[bm];
    for (int i = 0; i < 26; i++) {
      ans += cnt[bm ^ (1 << i)];
    }
    cnt[bm]++;
  }
  cout << ans << endl;
}