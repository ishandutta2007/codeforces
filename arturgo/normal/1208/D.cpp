#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

const int INFINI = 1000ll * 1000 * 1000 * 1000ll;

int doitAjouter[(1 << 20)];
int mini[(1 << 20)];

void update(int noeud) {
  if(noeud >= (1 << 19)) {
    mini[noeud] += doitAjouter[noeud];
    doitAjouter[noeud] = 0;
  }
  else {
    doitAjouter[2 * noeud] += doitAjouter[noeud];
    doitAjouter[2 * noeud + 1] += doitAjouter[noeud];
    doitAjouter[noeud] = 0;

    mini[noeud] = min(mini[2 * noeud] + doitAjouter[2 * noeud], mini[2 * noeud + 1] + doitAjouter[2 * noeud + 1]);
  }
}

int getPosMin(int n = 1) {
  update(n);

  if(n >= (1 << 19))
    return n - (1 << 19);

  if(mini[2 * n + 1] + doitAjouter[2 * n + 1] == 0)
    return getPosMin(2 * n + 1);
  return getPosMin(2 * n);
}

void setValeur(int pos, int nombre) {
  pos += (1 << 19);
  mini[pos] = nombre;
  while(pos != 0) {
    update(pos);
    pos /= 2;
  }
}

void ajoute(int deb, int fin, int val, int n = 1, int d = 0, int f = (1 << 19)) {
  update(n);

  if(deb >= f || d >= fin)
    return;
  if(deb <= d && f <= fin) {
    doitAjouter[n] += val;
    update(n);
    return;
  }

  int m = (d + f) / 2;
  ajoute(deb, fin, val, 2*n, d, m);
  ajoute(deb, fin, val, 2*n + 1, m, f);
  update(n);
}

int permu[(1 << 19)];

signed main() {
  ios_base::sync_with_stdio(false);
  int nbNombres;
  cin >> nbNombres;

  for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
    int nombre;
    cin >> nombre;
    
    setValeur(iNombre, nombre);
  }

  for(int iNombre = nbNombres;iNombre < (1 << 19);iNombre++)
    setValeur(iNombre, INFINI);

  for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
    int pos = getPosMin();
    permu[getPosMin()] = iNombre + 1;
    ajoute(pos + 1, nbNombres, -iNombre-1);
    setValeur(pos, INFINI);
  }

  for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
    cout << permu[iNombre] << " ";
  }
  return 0;
}