#include <iostream>

using namespace std;

int main () {
  int maxlen;
  
  cin >> maxlen;

  cout << (1LL << (maxlen + 1)) - 2 << endl;
}