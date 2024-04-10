#include <iostream>

using namespace std;

long long target [200005];

int main () {
  int length;
  cin >> length;
  for (int i = 0; i < length; i++) {
    cin >> target[i];
  }

  long long clevel = 0, qcount = 0;
  for (int i = 0; i < length; i++) {
    if (target[i] < clevel) {
      qcount += (clevel - target[i]);
      clevel = target[i];
    } else if (target[i] > clevel) {
      qcount += (target[i] - clevel);
      clevel = target[i];
    }
  }

  cout << qcount << endl;
}