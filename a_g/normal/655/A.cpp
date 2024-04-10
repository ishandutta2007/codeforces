#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  char A[2][2];
  char B[2][2];
  for (int i = 0; i < 2; i++) {
    string s;
    cin >> s;
    A[i][0] = s[0];
    A[i][1] = s[1];
  }
  for (int i = 0; i < 2; i++) {
    string s;
    cin >> s;
    B[i][0] = s[0];
    B[i][1] = s[1];
  }
  vector<pair<int, int>> L = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
  string U, V;
  for (int i = 0; i < 4; i++) {
    if (A[L[i].first][L[i].second] == 'A') {
      for (int j = 0; j < 4; j++) {
        char c = A[L[(i+j)%4].first][L[(i+j)%4].second];
        if (c != 'X') {
          U.push_back(c);
        }
      }
    }
    if (B[L[i].first][L[i].second] == 'A') {
      for (int j = 0; j < 4; j++) {
        char c = B[L[(i+j)%4].first][L[(i+j)%4].second];
        if (c != 'X') {
          V.push_back(c);
        }
      }
    }
  }
  cout << (U == V ? "YES" : "NO") << endl;
}