#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

int grille[1000][1000];

int tab[4][4] = {
  {8, 9, 1, 13},
  {3, 12, 7, 5},
  {0, 2, 4, 11},
  {6, 10, 15, 14}
};

int main() {
  ios_base::sync_with_stdio(false);
  int taille;
  cin >> taille;

  for(int iLig = 0;iLig < taille;iLig++) {
    for(int iCol = 0;iCol < taille;iCol++) {
      printf("%d ", tab[iLig % 4][iCol % 4] + 16 * ((iLig / 4) * (taille / 4) + (iCol / 4)));
    }
    printf("\n");
  }
  return 0;
}