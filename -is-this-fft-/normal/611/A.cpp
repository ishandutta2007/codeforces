#include <iostream>
#include <string>

using namespace std;

int main () {
  int count;
  string query;

  cin >> count >> query >> query;
  
  if (query == "week") {
    if (count == 5 || count == 6) {
      cout << 53 << endl;
    } else {
      cout << 52 << endl;
    }
  } else if (query == "month") {
    if (count <= 29) {
      cout << 12 << endl;
    } else if (count <= 30) {
      cout << 11 << endl;
    } else {
      cout << 7 << endl;
    }
  }
}