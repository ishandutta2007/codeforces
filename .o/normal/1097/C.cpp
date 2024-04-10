#include <bits/stdc++.h>

using namespace std;

int n;
char tmp[500050];

int cnt_opening[500050], cnt_closing[500050];

int main() {
  scanf("%d", &n);

  int cnt_correct = 0;

  for(int i = 0; i < n; i++) {
    scanf("%s", tmp);
    string s = tmp;

    int h = 0, m = 0;
    for(char c : s) {
      h += (c == '(') ? +1 : -1;
      m = min(m, h);
    }

    if(h == 0 && m == 0) {
      cnt_correct += 1;
    }else if(m == 0) {
      cnt_opening[h] += 1;
    }else {
      int hr = 0, mr = 0;
      reverse(s.begin(), s.end());
      for(char c : s) {
        hr += (c == ')') ? +1 : -1;
        mr = min(mr, hr);
      }
      if(mr == 0) cnt_closing[hr] += 1;
    }
  }

  long long ans = cnt_correct / 2;
  for(int i = 1; i <= 500000; i++) {
    ans += min(cnt_opening[i], cnt_closing[i]);
  }

  printf("%lld\n", ans);

  return 0;
}