#include <iostream>

using namespace std;

int main () {
  int score = 0;

  int gamec;
  cin >> gamec;

  for (int i = 0; i < gamec; i++) {
    int u, v;
    cin >> u >> v;
    
    score += (u > v);
    score -= (u < v);
  }

  if (score > 0) {
    cout << "Mishka" << endl;
  } else if (score < 0) {
    cout << "Chris" << endl;
  } else {
    cout << "Friendship is magic!^^" << endl;
  }
}