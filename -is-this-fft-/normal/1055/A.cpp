#include <iostream>

using namespace std;

const int maxn = 1005;

int forw [maxn], backw [maxn];

int main () {
  int statc, alice;
  cin >> statc >> alice;

  for (int i = 1; i <= statc; i++) {
    cin >> forw[i];
  }

  for (int i = 1; i <= statc; i++) {
    cin >> backw[i];
  }

  int common = -1;
  for (int i = 1; i <= statc; i++) {
    if (forw[i] && backw[i]) {
      common = i;
    }
  }

  if (forw[1] && forw[alice]) {
    cout << "YES" << '\n';
  } else if (forw[1] && backw[alice] && common >= alice) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << endl;
  }}