#include <iostream>
#include <string>

using namespace std;

int main () {
  string a, b;
  cin >> a >> b;

  if (a == b) {
    cout << -1 << endl;
  } else {
    cout << max((int) a.size(), (int) b.size()) << endl;
  }
}