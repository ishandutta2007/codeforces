#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int nbLigs, nbCols;
  scanf("%d%d", &nbLigs, &nbCols);

  for(int iLig = 0;iLig < nbLigs / 2;iLig++) {
    int nLig = iLig;
    int sLig = nbLigs - iLig - 1;

    for(int iCol = 0;iCol < nbCols;iCol++) {
      printf("%d %d\n", nLig + 1, iCol + 1);
      printf("%d %d\n", sLig + 1, nbCols - iCol);
    }
  }

  if(nbLigs % 2 == 1) {
    for(int iCol = 0;iCol < nbCols / 2;iCol++) {
      printf("%d %d\n", nbLigs / 2 + 1, iCol + 1);
      printf("%d %d\n", nbLigs / 2 + 1, nbCols - iCol);
    }

    if(nbCols % 2 == 1) {
      printf("%d %d\n", nbLigs / 2 + 1, nbCols / 2 + 1);
    }
  }
  
  return 0;
}