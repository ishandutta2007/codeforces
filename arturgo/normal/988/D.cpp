#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<long long> nombres;

int main() {
  int nbNombres;
  cin >> nbNombres;

  for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
    int nombre;
    cin >> nombre;
    nombres.insert(nombre);
  }

  vector<long long> melSuite;
  for(long long nombre : nombres) {
    for(int p2 = 0;p2 <= 30;p2++) {
      long long dec = 1ll << p2;
      long long cur = nombre;
      vector<long long> suite;
      while((int)suite.size() < 3 && nombres.find(cur) != nombres.end()) {
	suite.push_back(cur);
	cur += dec;
      }

      if(suite.size() > melSuite.size())
	melSuite = suite;
    }
  }

  cout << melSuite.size() << endl;
  for(int elem : melSuite) {
    cout << elem << " ";
  }
  cout << endl;
  return 0;
}