#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = count(s.begin(), s.end(), '2');
    if (c == 1 || c == 2) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
      vector<int> a;
      for (int i = 0; i < n; i++) {
        if (s[i] == '2') a.push_back(i);
      }
      vector<vector<char>> ans(n, vector<char>(n, '='));
      for (int i = 0; i < n; i++) ans[i][i] = 'X';
      int b = a.size();
      for (int i = 0; i < b; i++) {
        ans[a[i]][a[(i+1)%b]] = '+';
        ans[a[(i+1)%b]][a[i]] = '-';
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << ans[i][j];
        }
        cout << endl;
      }
    }
  }
}