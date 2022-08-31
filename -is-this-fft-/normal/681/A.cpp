#include <iostream>
#include <string>

using namespace std;

int main () {
  int particc;
  cin >> particc;

  bool wins = false;
  for (int i = 0; i < particc; i++) {
    string name;
    int before, after;
    cin >> name >> before >> after;
    
    if (before >= 2400 && after > before) {
      wins = true;
    }
  }

  cout << (wins ? "YES" : "NO") << endl;
}