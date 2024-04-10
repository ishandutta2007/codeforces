#include <iostream>

using namespace std;

int cnt [105];

int main () {
  int stopc;
  cin >> stopc;

  for (int i = 0; i < stopc; i++) {
    int tc;
    cin >> tc;

    for (int j = 0; j < tc; j++) {
      int ai;
      cin >> ai;
      cnt[ai]++;
    }
  }

  for (int i = 0; i < 105; i++) {
    if (cnt[i] == stopc) {
      cout << i << " ";
    }
  }
  cout << endl;
}