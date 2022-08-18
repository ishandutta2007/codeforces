#include <iostream>
#include <string>

using namespace std;

int main () {
  string aup, adn;
  cin >> aup >> adn;
  
  string acirc = "";
  if (aup[0] != 'X') {
    acirc += aup[0];
  }
  if (aup[1] != 'X') {
    acirc += aup[1];
  }
  if (adn[1] != 'X') {
    acirc += adn[1];
  }
  if (adn[0] != 'X') {
    acirc += adn[0];
  }

  if (acirc == "ABC" || acirc == "BCA" || acirc == "CAB") {
    acirc = "ABC";
  } else {
    acirc = "ACB";
  }

  string bup, bdn;
  cin >> bup >> bdn;
  
  string bcirc = "";
  if (bup[0] != 'X') {
    bcirc += bup[0];
  }
  if (bup[1] != 'X') {
    bcirc += bup[1];
  }
  if (bdn[1] != 'X') {
    bcirc += bdn[1];
  }
  if (bdn[0] != 'X') {
    bcirc += bdn[0];
  }

  if (bcirc == "ABC" || bcirc == "BCA" || bcirc == "CAB") {
    bcirc = "ABC";
  } else {
    bcirc = "ACB";
  }

  cout << (bcirc == acirc ? "YES\n" : "NO\n");
}