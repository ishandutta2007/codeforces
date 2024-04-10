#include <iostream>
#include <string>
#include <set>

using namespace std;

int main () {
  set<string> poss;
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    string name;
    cin >> name;

    if (poss.count(name) != 0) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }

    poss.insert(name);
  }
}