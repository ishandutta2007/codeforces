#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

int n, k;
char s[N];
stack <int> st;
int sibling[N];

int main() {
  scanf("%d %d %s", &n, &k, s + 1);

  for (int i = 1; i <= n; ++i) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      sibling[i] = st.top();
      sibling[st.top()] = i;
      st.pop();
    }
  }

  int ptr = 0;
  for (int i = 1; k > 0 and i <= n;) {
    if (s[i] == ')') {
      ++i;
      continue;
    }

    int j = sibling[i];
    int len = j - i + 1;

    if (len <= k) {
      k -= len;
      while (len--) {
        putchar(s[i++]);
      }
    } else {
      ++i;
    } 
  }
  puts("");
  return 0;
}