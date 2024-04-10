#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool found = 0;
    int ans = 1e9;
    for (char c = 'a'; c <= 'z'; c++) {
      int deletions = 0;
      int i = 0;
      int j = n-1;
      while (i < j) {
        char a = s[i];
        char b = s[j];
        if (a != b) {
          if (a == c) {
            deletions++;
            i++;
          }
          else if (b == c) {
            deletions++;
            j--;
          }
          else {
            break;
          }
        }
        else {
          i++;
          j--;
        }
      }
      if (i >= j) {
        found = 1;
        ans = min(ans, deletions);
      }
    }
    cout << (found ? ans : -1) << endl;
  }
}