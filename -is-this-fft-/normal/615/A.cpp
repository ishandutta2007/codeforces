#include <iostream>

const int MAX_B = 105;

using namespace std;

bool vis [MAX_B];

int main () {
  int buttonc, bulbc;
  cin >> buttonc >> bulbc;

  for (int i = 0; i < buttonc; i++) {
    int bbulbc;
    cin >> bbulbc;
    for (int j = 0; j < bbulbc; j++) {
      int bulb;
      cin >> bulb;
      vis[bulb] = true;
    }
  }

  bool ans = true;
  for (int i = 1; i <= bulbc; i++) {
    ans &= vis[i];
  }

  cout << (ans ? "YES" : "NO") << endl;
}