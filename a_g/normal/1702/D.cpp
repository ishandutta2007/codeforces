#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    int p;
    cin >> s >> p;
    int w = 0;
    vector<int> freq(26);
    for (char c: s) {
      freq[c-'a']++;
      w += c-'a'+1;
    }
    for (int i = 25; i >= 0; i--) {
      while (freq[i] && w > p) {
        freq[i]--;
        w -= i+1;
      }
    }
    for (char c: s) {
      if (freq[c-'a']) {
        cout << c;
        freq[c-'a']--;
      }
    }
    cout << '\n';
  }
}