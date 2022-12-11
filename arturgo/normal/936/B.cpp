#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> voisins[100 * 1000];

int etats[2][100 * 1000];

bool peutEgaliser;

vector<int> solution;

bool explore(int joueur, int sommet) {
  if(voisins[sommet].size() == 0) {
    if(joueur == 1) {
      solution.push_back(sommet);
      return true;
    }
    return false;
  }

  if(etats[joueur][sommet] == 1) {
    peutEgaliser = true;
    return false;
  }

  if(etats[joueur][sommet] == -1) {
    return false;
  }

  etats[joueur][sommet] = 1;
  for(int voisin : voisins[sommet]) {
    if(explore(1 - joueur, voisin)) {
      solution.push_back(sommet);
      return true;
    }
  }
  etats[joueur][sommet] = -1;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbVilles, nbRoutes;
  cin >> nbVilles >> nbRoutes;

  for(int iVille = 0;iVille < nbVilles;iVille++) {
    int taille;
    cin >> taille;

    for(int iRoute = 0;iRoute < taille;iRoute++) {
      int fin;
      cin >> fin;

      voisins[iVille].push_back(fin - 1);
    }
  }

  int posDebut;
  cin >> posDebut;

  bool peutGagner = explore(0, posDebut - 1);

  if(peutGagner) {
    cout << "Win" << endl;

    reverse(solution.begin(), solution.end());

    for(int elem : solution) {
      cout << elem + 1 << " ";
    }
    cout << endl;
  }
  else if(peutEgaliser) {
    cout << "Draw" << endl;
  }
  else {
    cout << "Lose" << endl;
  }
  return 0;
}