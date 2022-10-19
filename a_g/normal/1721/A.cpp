#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    vector<int> freq(26);
    for (int i = 0; i < 2; i++) {
      cin >> s;
      for (char c: s) {
        freq[c-'a']++;
      }
    }
    int m = *max_element(freq.begin(), freq.end());
    if (m == 4) {
      cout << "0\n";
      continue;
    }
    if (m == 3) {
      cout << "1\n";
      continue;
    }
    if (count(freq.begin(), freq.end(), 2) == 2) {
      cout << "1\n";
      continue;
    }
    if (m == 2) {
      cout << "2\n";
      continue;
    }
    cout << "3\n";
  }
}