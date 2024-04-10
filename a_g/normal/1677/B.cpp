#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int k = n*m;
    string s;
    cin >> s;
    vector<int> col(k);
    vector<int> row(k);
    vector<int> p(k+1);
    for (int i = 1; i <= k; i++) {
      p[i] = p[i-1] + (s[i-1] == '1');
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (s[j*m+i] == '1') {
          col[j*m+i]++;
          break;
        }
      }
      vector<int> z(n);
      for (int j = 0; j < n; j++) {
        int s = 0;
        if (j == 0) {
          s = p[m-i];
        }
        else {
          s = p[m*j+(m-i)] - p[m*(j-1)+(m-i)];
        }
        if (s) z[j]++;
        if (j) z[j] += z[j-1];
      }
      for (int l = m-1-i; l < k; l += m) {
        row[l] = z[l/m];
      }
    }
    for (int i = 1; i < k; i++) {
      col[i] += col[i-1];
    }

    for (int i = 0; i < k; i++) {
      cout << row[i]+col[i] << ' ';
    }
    cout << '\n';
  }
}