#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

long long tailles[100 * 1000 + 42];
int parents[100 * 1000 + 42];
int nbInters = 0;

int Find(int a) {
  if(parents[a] == -1)
    return a;
  return (parents[a] = Find(parents[a]));
}

void Union(int a, int b) {
  if(Find(a) == Find(b)) return;
  parents[Find(a)] = Find(b);
  nbInters--;
}

int main() {
  int nbPiles, nbReqs, taille;
  scanf("%d%d%d", &nbPiles, &nbReqs, &taille);

  for(int iPile = 0;iPile < nbPiles;iPile++) {
    parents[iPile] = -1;
    int t;
    scanf("%d", &t);
    tailles[iPile] = t;
    if(tailles[iPile] > taille) {
      nbInters++;
    }
  }

  for(int iPile = 1;iPile < nbPiles;iPile++) {
    if(tailles[iPile - 1] > taille && tailles[iPile] > taille) {
      Union(iPile, iPile - 1);
    }
  }

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int type;
    scanf("%d", &type);

    if(type == 0) {
      printf("%d\n", nbInters);
    }
    else {
      int pos, t;
      scanf("%d%d", &pos, &t);
      pos--;

      if(tailles[pos] <= taille && tailles[pos] + t > taille) {
	nbInters++;
	if(pos != 0 && tailles[pos - 1] > taille) {
	  Union(pos, pos - 1);
	}
	if(pos != nbPiles - 1 && tailles[pos + 1] > taille) {
	  Union(pos, pos + 1);
	}
      }

      tailles[pos] += t;
    }
  }
  return 0;
}