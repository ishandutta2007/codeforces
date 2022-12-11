#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define int long long
using namespace std;

int nombres[300 * 1000];

int32_t main() {
  ios_base::sync_with_stdio(false);
  
  int nbTailles;
  cin >> nbTailles;
  
  for(int iTaille = 0;iTaille < nbTailles;iTaille++) {
    cin >> nombres[iTaille];
  }
  
  int nbConstruit = 0;
  int nbCherchent = 0;
  for(int iTaille = nbTailles - 1;iTaille >= 0;iTaille--) {
    nbCherchent += nombres[iTaille] / 2;
    
    if(nombres[iTaille] % 2 == 1 && nbCherchent != 0) {
      nbCherchent--;
      nbConstruit++;
    }
  }
  
  nbConstruit += nbCherchent * 2 / 3;
  
  cout << nbConstruit << endl;
  return 0;
}