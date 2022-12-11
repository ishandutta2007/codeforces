#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

vector<int> voisins[2000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbTests;
  cin >> nbTests;

  for(int iTest = 0;iTest < nbTests;iTest++) {
    int nbVilles, nbRoutes;
    cin >> nbVilles >> nbRoutes;

    vector<bitset<2001>> lignes(nbVilles, 0);
    
    for(int iRoute = 0;iRoute < nbRoutes;iRoute++) {
      int deb, fin;
      cin >> deb >> fin;
      deb--; fin--;
      voisins[deb].push_back(fin);
      voisins[fin].push_back(deb);
      lignes[deb][fin] = 1;
      lignes[fin][deb] = 1;
    }

    bool possible_1 = true;
    for(int iVille = 0;iVille < nbVilles;iVille++) {
      if(voisins[iVille].size() % 2 == 1) {
	lignes[iVille][iVille] = 1;
	lignes[iVille][2000] = 1;
	possible_1 = false;
      }
    }

    if(possible_1) {
      cout << 1 << endl;
      for(int iVille = 0;iVille < nbVilles;iVille++) {
	cout << 1 << " ";
      }
      cout << endl;
    }
    else {
      for(int iLigne = 0;iLigne < nbVilles;iLigne++) {
	for(int iAutre = iLigne;iAutre < nbVilles;iAutre++) {
	  if(lignes[iAutre][iLigne] == 1) {
	    swap(lignes[iAutre], lignes[iLigne]);
	    break;
	  }
	}

	for(int iAutre = 0;iAutre < nbVilles;iAutre++) {
	  if(iAutre != iLigne && lignes[iAutre][iLigne] == 1) {
	    lignes[iAutre] ^= lignes[iLigne];
	  }
	}
      }

      cout << 2 << endl;
      for(int iVille = 0;iVille < nbVilles;iVille++) {
	cout << 1 + (int)lignes[iVille][2000] << " ";
      }
      cout << endl;
    }

    for(int iVille = 0;iVille < nbVilles;iVille++) {
      voisins[iVille].clear();
    }
  }

  return 0;
}