#include <iostream>

const int INF = 1023456789;

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int length, arrc;
  cin >> length >> arrc;

  int minlength = INF;
  for (int i = 0; i < arrc; i++) {
    int l, r;
    cin >> l >> r;

    minlength = min(minlength, r - (l - 1));
  }

  cout << minlength << endl;
  for (int i = 0; i < length; i++) {
    cout << i % minlength << (i == length - 1 ? '\n' : ' ');
  }
}