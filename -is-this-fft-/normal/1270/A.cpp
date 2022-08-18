#include <iostream>

using namespace std;

void solve () {
  int n, fc, sc;
  cin >> n >> fc >> sc;

  int fmx = -1;
  for (int i = 0; i < fc; i++) {
    int x;
    cin >> x;

    fmx = max(x, fmx);
  }

  int smx = -1;
  for (int i = 0; i < sc; i++) {
    int x;
    cin >> x;

    smx = max(x, smx);
  }

  if (fmx > smx) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}