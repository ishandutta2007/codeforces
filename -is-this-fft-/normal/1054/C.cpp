#include <iostream>

using namespace std;

const int maxn = 1005;

int cntl [maxn], cntr [maxn];
int candy [maxn];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> cntl[i];
  }

  for (int i = 0; i < length; i++) {
    cin >> cntr[i];
  }

  for (int i = 0; i < length; i++) {
    candy[i] = length - cntl[i] - cntr[i];
  }

  for (int i = 0; i < length; i++) {
    int reall = 0, realr = 0;
    for (int j = 0; j < i; j++) {
      if (candy[j] > candy[i]) {
        reall++;
      }
    }

    for (int j = i + 1; j < length; j++) {
      if (candy[j] > candy[i]) {
        realr++;
      }
    }

    if (cntl[i] != reall) {
      cout << "NO" << endl;
      return 0;
    }

    if (cntr[i] != realr) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < length; i++) {
    cout << candy[i] << " ";
  }
  cout << endl;
}