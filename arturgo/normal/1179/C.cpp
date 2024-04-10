#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int doitAjouter[(1 << 21)];
int maxSous[(1 << 21)];

void update(int noeud) {
  if(noeud < (1 << 20)) {
    doitAjouter[2 * noeud] += doitAjouter[noeud];
    doitAjouter[2 * noeud + 1] += doitAjouter[noeud];
    doitAjouter[noeud] = 0;

    maxSous[noeud] = max(maxSous[2 * noeud] + doitAjouter[2 * noeud],
			 maxSous[2 * noeud + 1] + doitAjouter[2 * noeud + 1]);
  }
}

void ajoute(int deb, int fin, int val, int d = 0, int f = (1 << 20), int n = 1) {
  update(n);
  if(f <= deb || fin <= d)
    return;
  if(deb <= d && f <= fin) {
    doitAjouter[n] += val;
    return;
  }
  int m = (d + f) / 2;
  ajoute(deb, fin, val, d, m, 2 * n);
  ajoute(deb, fin, val, m, f, 2 * n + 1);
  update(n);
}

int melPlat(int d = 0, int f = (1 << 20), int n = 1) {
  update(n);

  if(maxSous[n] + doitAjouter[n] <= 0) {
    return -1;
  }
  if(f - d == 1)
    return d;
  
  int m = (d + f) / 2;

  int droite = melPlat(m, f, 2 * n + 1);
  if(droite != -1) return droite;
  int gauche = melPlat(d, m, 2 * n);
  if(gauche != -1) return gauche;
  return -1;
}

int prixPlat[300 * 1000];
int prixEleve[300 * 1000];

int main() {
  int nbPlats, nbEleves;
  scanf("%d%d", &nbPlats, &nbEleves);

  for(int iPlat = 0;iPlat < nbPlats;iPlat++) {
    int prix;
    scanf("%d", &prix);
    prixPlat[iPlat] = prix;
    ajoute(0, prix + 1, 1);
  }

  for(int iEleve = 0;iEleve < nbEleves;iEleve++) {
    int prix;
    scanf("%d", &prix);
    prixEleve[iEleve] = prix;
    ajoute(0, prix + 1, -1);
  }

  int nbReqs;
  scanf("%d", &nbReqs);

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int type, id, val;
    scanf("%d%d%d", &type, &id, &val);
    id--;

    if(type == 1) {
      ajoute(0, prixPlat[id] + 1, -1);
      prixPlat[id] = val;
      ajoute(0, prixPlat[id] + 1, 1);
    }
    else {
      ajoute(0, prixEleve[id] + 1, 1);
      prixEleve[id] = val;
      ajoute(0, prixEleve[id] + 1, -1);
    }

    printf("%d\n", melPlat());
  }
  
  return 0;
}