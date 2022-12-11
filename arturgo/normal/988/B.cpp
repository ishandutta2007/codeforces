#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> chaines;

bool compSize(string a, string b) {
  return a.size() < b.size();
}

int main() {
  int nbChaines;
  cin >> nbChaines;

  for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
    string chaine;
    cin >> chaine;
    chaines.push_back(chaine);
  }

  sort(chaines.begin(), chaines.end(), compSize);

  for(int iChaine = 0;iChaine < nbChaines - 1;iChaine++) {
    if(chaines[iChaine + 1].find(chaines[iChaine]) == string::npos) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  for(string chaine : chaines)
    cout << chaine << endl;

  return 0;
}