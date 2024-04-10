#include <bits/stdc++.h>
using namespace std;

int freq[26];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string s, t;
    cin >> s >> t;
    string u;
    for (char c: t) {
      freq[c-'A']++;
    }
    reverse(s.begin(), s.end());
    for (char c: s) {
      if (freq[c-'A']) {
        u.push_back(c);
        freq[c-'A']--;
      }
    }
    reverse(u.begin(), u.end());
    cout << (t == u ? "YES" : "NO") << '\n';

    fill(freq, freq+26, 0);
  }
}