#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<pair<int, int>, int> ouverts;
vector<pair<int, int>> queries[(1 << 20)];
long long solutions[(1 << 19)];

int parents[600 * 1000 + 20];
int taille[600 * 1000 + 20];
int tailleLig[600 * 1000 + 20];
int tailleCol[600 * 1000 + 20];

void ajoute(pair<int, int> coords, int deb, int fin) {
  deb += (1 << 19);
  fin += (1 << 19);

  while(deb < fin) {
    if(deb % 2 == 1) {
      queries[deb].push_back(coords);
      deb++;
    }
    if(fin % 2 == 1) {
      fin--;
      queries[fin].push_back(coords);
    }
    deb /= 2;
    fin /= 2;
  }
}

int Find(int a) {
  if(parents[a] == -1)
    return a;
  return Find(parents[a]);
}
	   
vector<int> changements;
long long curVal = 0;

void annule() {
  int a = changements.back();
  changements.pop_back();
  
  if(a == -1)
    return;
  
  curVal -= tailleLig[parents[a]] * (long long)tailleCol[parents[a]];
  taille[parents[a]] -= taille[a];
  tailleLig[parents[a]] -= tailleLig[a];
  tailleCol[parents[a]] -= tailleCol[a];
  curVal += tailleLig[a] * (long long)tailleCol[a];
  curVal += tailleLig[parents[a]] * (long long)tailleCol[parents[a]];
  parents[a] = -1;
}

void Union(int a, int b) {
  a = Find(a);
  b = Find(b);

  if(a == b) {
    changements.push_back(-1);
    return;
  }
  
  if(taille[a] > taille[b]) {
    Union(b, a);
    return;
  }
  
  changements.push_back(a);
  parents[a] = b;
  
  curVal -= tailleLig[b] * (long long)tailleCol[b];
  curVal -= tailleLig[a] * (long long)tailleCol[a];
  taille[b] += taille[a];
  tailleLig[b] += tailleLig[a];
  tailleCol[b] += tailleCol[a];
  curVal += tailleLig[b] * (long long)tailleCol[b];
}

void calculeSols(int noeud = 1) {
  for(pair<int, int> coords : queries[noeud]) {
    Union(coords.first, 300 * 1000 + 10 + coords.second);
  }

  if(noeud >= (1 << 19)) {
    solutions[noeud - (1 << 19)] = curVal;
  }
  else {
    calculeSols(2 * noeud);
    calculeSols(2 * noeud + 1);
  }

  for(pair<int, int> coords : queries[noeud]) {
    annule();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbReqs;
  cin >> nbReqs;

  for(int iNoeud = 0;iNoeud < 600 * 1000 + 20;iNoeud++) {
    taille[iNoeud] = 1;
    parents[iNoeud] = -1;

    if(iNoeud < 300 * 1000 + 10)
      tailleLig[iNoeud] = 1;
    else
      tailleCol[iNoeud] = 1;
  }

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int lig, col;
    cin >> lig >> col;
    if(ouverts.find({lig, col}) != ouverts.end()) {
      ajoute({lig, col}, ouverts[{lig, col}], iReq);
      ouverts.erase({lig, col});
    }
    else {
      ouverts[{lig, col}] = iReq;
    }
  }

  for(pair<pair<int, int>, int> ouvert : ouverts) {
    ajoute(ouvert.first, ouvert.second, nbReqs);
  }
  calculeSols();

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    cout << solutions[iReq] << " ";
  }
  cout << endl;

  return 0;
}