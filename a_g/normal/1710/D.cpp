#include <bits/stdc++.h>
using namespace std;

// based on https://codeforces.com/contest/1710/submission/165606079

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> con(n);
    for (string& row: con) cin >> row;
    // stack stores the left endpoints of connected components
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      stk.push(i);
      for (int j = i-1; j >= 0; j--) {
        if (con[j][i-j]=='1') {
          cout << i+1 << ' ' << j+1 << '\n';
          stk.pop();
          if (stk.top() > j) {
            cout << j+1 << ' ' << stk.top()+1 << '\n';
            stk.pop();
            while (stk.top() > j) {
              cout << stk.top()+1 << ' ' << i+1 << '\n';
              stk.pop();
            }
          }
          j = min(j, stk.top());
        }
      }
    }
  }
}