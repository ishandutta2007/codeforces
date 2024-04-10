#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1610/submission/136815867
// seems like by amortized analysis, the compare function does O(n) character
// comparisons

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  stack<int> stk;
  vector<int> jmp(n+1);
  // jmp[i] = which index to go to after including s[i-1]
  auto compare = [&] (int i, int j) {
    while (i < n && j < n) {
      if (s[i] != s[j]) return s[i] < s[j];
      i = jmp[i+1];
      j = jmp[j+1];
    }
    return i == n && j < n;
  };

  jmp[n] = n;
  stk.push(n);
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '(') {
      jmp[i] = i;
      stk.pop();
      // let j be at top of stack
      // f(s[i:]) = min(f(s[j+1:]), '('+f(s[i+1:]))
      // there's nothing to match this
      if (stk.empty()) stk.push(i);
      // it's better to include s[i] than not, so replace the top element
      else if (compare(i, stk.top())) stk.top() = i;
      // it's better to not include s[i]
      else jmp[i] = stk.top();
    }
    else {
      stk.push(i);
      jmp[i] = i;
    }
  }
  for (int i = 0; i < n; i = jmp[i+1]) cout << s[i];
  cout << '\n';
}