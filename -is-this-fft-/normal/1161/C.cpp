#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int pilec;
  cin >> pilec;

  vector<int> piles (pilec);
  for (int i = 0; i < pilec; i++) {
    cin >> piles[i];
  }

  int least = 1000;
  for (int i = 0; i < pilec; i++) {
    least = min(least, piles[i]);
  }
  int leastc = 0;
  for (int i = 0; i < pilec; i++) {
    leastc += piles[i] == least;
  }

  if (leastc > pilec / 2) {
    cout << "Bob" << '\n';
  } else {
    cout << "Alice" << '\n';
  }
}