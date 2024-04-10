#include <iostream>

const int MAX_ISLE = 200005;

using namespace std;

int old [MAX_ISLE];
int nu [MAX_ISLE];
int onxt [MAX_ISLE];
int nnxt [MAX_ISLE];

int main () {
  int islec;
  cin >> islec;

  for (int i = 0; i < islec; i++) {
    cin >> old[i];
  }

  for (int i = 0; i < islec; i++) {
    cin >> nu[i];
  }

  for (int i = 0; i < islec; i++) {
    if (old[(i + 1) % islec] == 0) {
      onxt[old[i]] = old[(i + 2) % islec];
    } else {
      onxt[old[i]] = old[(i + 1) % islec];
    }

    if (nu[(i + 1) % islec] == 0) {
      nnxt[nu[i]] = nu[(i + 2) % islec];
    } else {
      nnxt[nu[i]] = nu[(i + 1) % islec];
    }
  }

  bool flag = true;
  for (int i = 1; i < islec; i++) {
    if (onxt[i] != nnxt[i]) {
      flag = false;
    }
  }

  cout << (flag ? "YES" : "NO") << endl;
}