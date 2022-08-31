#include <iostream>

const int MAX_BALL = 1005;

using namespace std;

bool can [MAX_BALL];

int main () {
  ios::sync_with_stdio(false);

  int ballc;
  cin >> ballc;
  for (int i = 0; i < ballc; i++) {
    int ball;
    cin >> ball;
    can[ball] = true;
  }

  for (int i = 1; i < MAX_BALL - 1; i++) {
    if (can[i - 1] && can[i] && can[i + 1]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}