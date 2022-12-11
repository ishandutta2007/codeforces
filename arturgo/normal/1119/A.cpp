#include <iostream>
#include <vector>
using namespace std;

int main() {
  int nbVilles;
  cin >> nbVilles;
  
  vector<int> couleurs;
  for(int iVille = 0;iVille < nbVilles;iVille++) {
    int couleur;
    cin >> couleur;
    couleurs.push_back(couleur);
  }
  
  int tailleFin = nbVilles - 1;
  while(couleurs[tailleFin] == couleurs[0])
    tailleFin--;
   
  int tailleDeb = nbVilles - 1;
  while(couleurs[nbVilles - 1 - tailleDeb] == couleurs.back())
    tailleDeb--;
   
  cout << max(tailleDeb, tailleFin) << endl;
  return 0;
}