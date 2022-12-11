#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int nbChiffres, nbStop;
int etats[2001];

string chaines[10] = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int chiffres[10];

bool estPasse[2][2001][2001];
bool estPossible[2][2001][2001];

bool possible(bool aC, int pos, int reste) {
   if(reste < 0)
      return false;
   if(pos == nbChiffres)
      return reste == 0    ;
   
   if(estPasse[aC][pos][reste])
      return estPossible[aC][pos][reste];
   estPasse[aC][pos][reste] = true;
   
   bool estPos = false;
   
   if(etats[pos] == 0 && !aC)
      estPos = possible(false, pos + 1, reste);
   
   for(int iChiffre = 0;iChiffre < 10;iChiffre++) {
      if((etats[pos] | chiffres[iChiffre]) == chiffres[iChiffre]
      && possible(true, pos + 1, reste - __builtin_popcount(etats[pos] ^ chiffres[iChiffre]))) {
         estPos = true;
      }
   }
   
   return (estPossible[aC][pos][reste] = estPos);
}

signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> nbChiffres >> nbStop;
   
   for(int i = 0;i < 10;i++) {
      for(int iBit = 0;iBit < 7;iBit++) {
         if(chaines[i][iBit] == '1')
            chiffres[i] |= (1 << iBit);
      }
   }
   
   for(int iChiffre = 0;iChiffre < nbChiffres;iChiffre++) {
      for(int iBit = 0;iBit < 7;iBit++) {
         char car;
         cin >> car;
         
         if(car == '1')
            etats[iChiffre] |= (1 << iBit);
      }
   }
   
   if(!possible(false, 0, nbStop)) {
      cout << -1 << endl;
      return 0;
   }
   
   bool aC = false;
   int reste = nbStop;
   
   for(int iPos = 0;iPos < nbChiffres;iPos++) {
      for(int chiffre = 9;chiffre >= 0;chiffre--) {
         if((etats[iPos] | chiffres[chiffre]) == chiffres[chiffre]
         && possible(aC, iPos + 1, reste - __builtin_popcount(etats[iPos] ^ chiffres[chiffre]))) {
            cout << chiffre;
            aC = true;
            reste -=  __builtin_popcount(etats[iPos] ^ chiffres[chiffre]);
            break;
         }
      }
   }
   cout << endl;
   return 0;
}