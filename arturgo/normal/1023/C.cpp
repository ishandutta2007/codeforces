#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int nbKicks = s.size() / 2 - k / 2;

  string chaine;
  for(char car : s) {
    if(car == '(') {
      chaine.push_back('(');
    }
    else if(nbKicks != 0) {
      nbKicks--;
      chaine.pop_back();
    }
    else {
      chaine.push_back(')');
    }
  }

  cout << chaine << endl;
  return 0;
}