#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n; char s[N];

bool good() {
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') ++sum;
    else --sum;
    if (sum < 0) return 0;
  }
  return sum == 0;
}

int main() {
  scanf("%d %s", &n, s + 1);
  int op = 0, cl = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') ++op; 
    else ++cl;
  }
  if (op ^ cl) {
    puts("No"); return 0;
  }
  if (good()) {
    puts("Yes"); return 0;
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') ++sum;
    else --sum;
    if (sum < 0) {
      assert(s[i] == ')');
      for (int j = i; j < n; ++j) {
        s[j] = s[j + 1];
      }
      s[n] = ')';
      break;
    }
  }
  puts(good() ? "Yes" : "No");
  return 0;
}