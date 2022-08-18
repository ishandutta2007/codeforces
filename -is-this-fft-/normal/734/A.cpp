#include <iostream>
#include <string>

using namespace std;

int main () {
  int ac = 0, dc = 0, gamec;
  string games;
  cin >> gamec >> games;

  for (int i = 0; i < (int) games.size(); i++) {
    if (games[i] == 'A') {
      ac++;
    } else {
      dc++;
    }
  }

  if (ac > dc) {
    cout << "Anton" << endl;
  } else if (ac < dc) {
    cout << "Danik" << endl;
  } else {
    cout << "Friendship" << endl;
  }
}