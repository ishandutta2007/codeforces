#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

char s[7];
long long x, ans;
int n, a, b, c, d;
priority_queue <long long> B, C, D;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s %lld", s, &x);
    ans += x;
    if (s[0] == '0' and s[1] == '0') ++d, D.push(-x);
    if (s[0] == '0' and s[1] == '1') ++b, B.push(-x);
    if (s[0] == '1' and s[1] == '0') ++c, C.push(-x);
    if (s[0] == '1' and s[1] == '1') ++a;
  }
  if (b < c) B.swap(C), swap(b, c);
  while (a < d) {
    ans += D.top(); D.pop(); --d;
  }
  while (a - d < b - c) {
    if (D.empty()) {ans += B.top(); B.pop(); --b;}
    else if (B.empty()) {ans += D.top(); D.pop(); --d;}
    else {
      if (B.top() > D.top()) {ans += B.top(); B.pop(); --b;}
      else {ans += D.top(); D.pop(); --d;} 
    }
  }
  // cout << a << " " << b << " " << c << " " << d << endl;
  cout << ans << '\n';
  return 0;
}

// a - d >= |c - b|