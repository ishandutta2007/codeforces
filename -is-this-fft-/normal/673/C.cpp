#include <iostream>

const int MAX_BALL = 5005;

using namespace std;

int color [MAX_BALL], cnt [MAX_BALL], ans [MAX_BALL];

int main () {
  int ballc;
  cin >> ballc;
  
  for (int i = 0; i < ballc; i++) {
    cin >> color[i];
  }

  for (int i = 0; i < ballc; i++) {
    for (int j = 0; j < MAX_BALL; j++) {
      cnt[j] = 0;
    }

    int domcolor = 0, domcnt = 0;
    for (int j = i; j < ballc; j++) {
      cnt[color[j]]++;
      if (cnt[color[j]] > domcnt ||
          (cnt[color[j]] == domcnt && color[j] < domcolor)) {
        domcolor = color[j];
        domcnt = cnt[color[j]];
      }
      ans[domcolor]++;
    }
  }

  for (int i = 1; i <= ballc; i++) {
    cout << ans[i] << (i == ballc ? '\n' : ' ');
  }
}