#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int nbObjets;
  long long maxHauteur;
  cin >> nbObjets >> maxHauteur;
  
  int maxi = 0;
  
  multiset<long long> hauteurs;
  for(int iObjet = 0;iObjet < nbObjets;iObjet++) {
    long long hauteur;
    cin >> hauteur;
    hauteurs.insert(-hauteur);
    
    long long somme = 0, indice = 0;
    for(auto h : hauteurs) {
      if(indice % 2 == 0)
        somme -= h;
      indice++;
    }
    
    if(somme <= maxHauteur) {
      maxi = max(maxi, iObjet + 1);
    }
  }
  
  cout << maxi << endl;
  return 0;
}