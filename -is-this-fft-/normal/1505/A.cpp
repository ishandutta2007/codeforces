#include <iostream>

using namespace std;

int main () {
  while (true) {
    string trash;
    getline(cin, trash);
    if (cin.eof()) {
      return 0;
    }
    cout << "NO" << endl;
  }
}