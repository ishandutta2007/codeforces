#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<int> counts(26);
    for (char c: s) {
      int i = c-'a';
      if (counts[i] < 2) counts[i]++;
    }
    cout << accumulate(counts.begin(), counts.end(), 0)/2 << endl;
  }
}