#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<long long> elems;

int tailleGrand, taillePetit;
int nbPetits, nbGrands;

const int MOD = 50 * 1000 * 1000 + 7;

int dyn[MOD];
bool estPasse[MOD];

inline int hashe(int pos, int curGrands) {
  return ( (long long)301* 1000*curGrands + pos ) % MOD;
}

int minCout(int pos, int curGrands) {
  if(pos == (int)elems.size())
    return 0;
  if(estPasse[hashe(pos, curGrands)])
    return dyn[hashe(pos, curGrands)];
  estPasse[hashe(pos, curGrands)] = true;

  long long val = 2000 * 1000 * 1000;

  int curPetits = (pos - tailleGrand * curGrands) / taillePetit;
  if(curPetits < nbPetits && taillePetit != 0) {
    val = min(val, elems[pos + taillePetit - 1] - elems[pos] + minCout(pos + taillePetit, curGrands));
  }
  if(curGrands < nbGrands) {
    val = min(val, elems[pos + tailleGrand - 1] - elems[pos] + minCout(pos + tailleGrand, curGrands + 1));
  }

  dyn[hashe(pos, curGrands)] = val;
  return val;
}

int main() {
  int nbElems, k;
  scanf("%d%d", &nbElems, &k);

  for(int iElem = 0;iElem < nbElems;iElem++) {
    int elem;
    scanf("%d", &elem);
    elems.push_back(elem);
  }

  nbGrands = nbElems % k;
  nbPetits = k - nbGrands;
  taillePetit = nbElems / k;
  tailleGrand = taillePetit + 1;

  sort(elems.begin(), elems.end());

  printf("%d\n", minCout(0, 0));
  
  return 0;
}