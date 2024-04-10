#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

const int MOD = 998244353;

string lettres, prefixe;

int nbManieres[3001][3001];

signed main() {
   ios_base::sync_with_stdio(false);
   
   cin >> lettres >> prefixe;
   
   if(lettres.size() < prefixe.size()) {
      cout << 0 << endl;
      return 0;
   }
   
   for(int iDeb = 0;iDeb < (int)lettres.size();iDeb++) {
      if(iDeb >= (int)prefixe.size() || lettres[0] == prefixe[iDeb]) {
         nbManieres[1][iDeb] = 1;
      }
   }
   
   for(int iTaille = 1;iTaille < (int)lettres.size();iTaille++) {
      for(int iDeb = 0;iDeb + iTaille <= (int)lettres.size();iDeb++) {
         if(iDeb >= 0) {
            if(iDeb - 1 >= (int)prefixe.size() || lettres[iTaille] == prefixe[iDeb - 1]) {
               nbManieres[iTaille + 1][iDeb - 1] = 
                  (nbManieres[iTaille + 1][iDeb - 1] + nbManieres[iTaille][iDeb]) % MOD;
            }
         }
         
         if(iDeb + iTaille < (int)lettres.size()) {
            if(iDeb + iTaille >= (int)prefixe.size() || lettres[iTaille] == prefixe[iDeb + iTaille]) {
               nbManieres[iTaille + 1][iDeb] = 
                  (nbManieres[iTaille + 1][iDeb] + nbManieres[iTaille][iDeb]) % MOD;
            }
         }
      }
   }
   
   int somme = 0;
   
   for(int iTaille = (int)prefixe.size();iTaille <= (int)lettres.size();iTaille++) {
      somme = (somme + nbManieres[iTaille][0]) % MOD;
   }
   
   cout << (2 * somme) % MOD << endl;
   
   return 0;
}