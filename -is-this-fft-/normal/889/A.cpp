#include <iostream>

using namespace std;

const int MAX_V = 200005;

int cnt [MAX_V];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    int pt;
    cin >> pt;

    cnt[pt] ++;
  }

  int ans = 0;
  for (int i = 0; i < MAX_V; i++) {
    ans += max(cnt[i] - 1, 0);
  }

  cout << ans + 1 << endl;
}