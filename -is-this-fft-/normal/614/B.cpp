#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_perfect (string s) {
  if (s.at(0) != '1') {
    return false;
  }

  for (int i = 1; i < s.size(); i++) {
    if (s.at(i) != '0') {
      return false;
    }
  }

  return true;
}

int main () {
  int countryc;
  cin >> countryc;
 
  int zeroc = 0;
  string ugly = "1";
  for (int i = 0; i < countryc; i++) {
    string s;
    cin >> s;
    if (s == "0") {
      cout << "0" << endl;
      return 0;
    } else if (is_perfect(s)) {
      zeroc += s.size() - 1;
    } else {
      ugly = s;
    }
  }

  cout << ugly;
  for (int i = 0; i < zeroc; i++) {
    cout << '0';
  }
  cout << endl;
  return 0;
}