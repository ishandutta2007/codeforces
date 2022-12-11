#include <iostream>
#include <vector>
using namespace std;

int types[1000 * 1000];

int resteRequis;
int necessaires[1000 * 1000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbFleurs, nbCollier, nbPieces, nbParfaite;
  cin >> nbFleurs >> nbCollier >> nbPieces >> nbParfaite;

  for(int iFleur = 0;iFleur < nbFleurs;iFleur++) {
    cin >> types[iFleur];
  }

  for(int iParfaite = 0;iParfaite < nbParfaite;iParfaite++) {
    int type;
    cin >> type;
    if(necessaires[type] == 0) {
      resteRequis++;
    }
    necessaires[type]++;
  }

  int iFin = 0;
  for(int iDebut = 0;iDebut < nbFleurs;) {
    while(resteRequis != 0 || iFin - iDebut < nbCollier) {
      if(iFin == nbFleurs) {
	cout << -1 << endl;
	return 0;
      }
      
      necessaires[types[iFin]]--;
      if(necessaires[types[iFin]] == 0)
	resteRequis--;
      iFin++;
    }

    if(iFin - iDebut <= nbFleurs - (nbPieces - 1) * nbCollier) {
      cout << iFin - iDebut - nbCollier << endl;
      vector<int> pasNecessaires;
      for(int iFois = iDebut;iFois < iFin;iFois++) {
	if(necessaires[types[iFois]] < 0) {
	  pasNecessaires.push_back(iFois);
	}
	necessaires[types[iFois]]++;
      }

      for(int iSuppr = 0;iSuppr < iFin - iDebut - nbCollier;iSuppr++) {
	cout << pasNecessaires[iSuppr] + 1 << " ";
      }
      cout << endl;
      return 0;
    }

    for(int iFois = 0;iFois < nbCollier && iDebut + iFois < nbFleurs;iFois++) {
      necessaires[types[iDebut + iFois]]++;
      if(necessaires[types[iDebut + iFois]] == 1)
	resteRequis++;
    }
    iDebut += nbCollier;
  }

  cout << -1 << endl;
  return 0;
}