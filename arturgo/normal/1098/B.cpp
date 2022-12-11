#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int nbLigs, nbCols;
vector<string> lignes;
vector<string> lettres = {"A", "T", "G", "C"};

int compare(vector<string>& autre) {
  int nbDiffs = 0;
  for(int iLig = 0;iLig < nbLigs;iLig++) {
    for(int iCol = 0;iCol < nbCols;iCol++)
      if(lignes[iLig][iCol] != autre[iLig][iCol])
	nbDiffs++;
  }
  return nbDiffs;
}

vector<string> genHor(string p, string i) {
  vector<string> grille = vector<string>(nbLigs, string(nbCols, ' '));

  for(int iLig = 0;iLig < nbLigs;iLig++) {
    string valide = i;
    if(iLig % 2 == 0) valide = p;

    int scoreN = 0, scoreI = 0;
    for(int iCol = 0;iCol < nbCols;iCol++) {
      if(lignes[iLig][iCol] != valide[iCol % 2])
	scoreN++;
      if(lignes[iLig][iCol] != valide[(iCol + 1) % 2])
	scoreI++;
    }

    string mel = valide;
    if(scoreI < scoreN) {
      reverse(mel.begin(), mel.end());
    }

    for(int iCol = 0;iCol < nbCols;iCol++) {
      grille[iLig][iCol] = mel[iCol % 2];
    }
  }

  return grille;
}

vector<string> genVer(string p, string i) {
  vector<string> grille = vector<string>(nbLigs, string(nbCols, ' '));

  for(int iCol = 0;iCol < nbCols;iCol++) {
    string valide = i;
    if(iCol % 2 == 0) valide = p;

    int scoreN = 0, scoreI = 0;
    for(int iLig = 0;iLig < nbLigs;iLig++) {
      if(lignes[iLig][iCol] != valide[iLig % 2])
	scoreN++;
      if(lignes[iLig][iCol] != valide[(iLig + 1) % 2])
	scoreI++;
    }

    string mel = valide;
    if(scoreI < scoreN) {
      reverse(mel.begin(), mel.end());
    }

    for(int iLig = 0;iLig < nbLigs;iLig++) {
      grille[iLig][iCol] = mel[iLig % 2];
    }
  }

  return grille;
}

signed main() {
  ios_base::sync_with_stdio(false);

  cin >> nbLigs >> nbCols;

  for(int iLig = 0;iLig < nbLigs;iLig++) {
    string ligne;
    cin >> ligne;
    lignes.push_back(ligne);
  }

  vector<vector<string>> grilles;
  for(string prem : lettres) {
    for(string sec : lettres) {
      if(sec > prem) {
	for(string ter : lettres) {
	  if(ter != sec && ter != prem) {
	    for(string quad : lettres) {
	      if(quad != sec && quad != prem && quad > ter) {
		grilles.push_back(genHor(prem + sec, ter + quad));
		grilles.push_back(genVer(prem + sec, ter + quad));
	      }
	    }
	  }
	}
      }
    }
  }

  int minDiff = nbLigs * nbCols;
  int melPos = 0;
  for(int iGrille = 0;iGrille < (int)grilles.size();iGrille++) {
    
    int curDiff = compare(grilles[iGrille]);
    if(curDiff < minDiff) {
      minDiff = curDiff;
      melPos = iGrille;
    }
  }

  for(int iLig = 0;iLig < nbLigs;iLig++) {
    cout << grilles[melPos][iLig] << endl;
  }
  return 0;
}