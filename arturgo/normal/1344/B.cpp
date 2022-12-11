#include <iostream>
#define int long long

using namespace std;

string terrain[1000];

int nbLigs, nbCols;

void colorie(int lig, int col) {
   if(lig < 0 || col < 0 || lig >= nbLigs || col >= nbCols) {
      return;
   }
   if(terrain[lig][col] == '.')
      return;
   terrain[lig][col] = '.';
   
   colorie(lig - 1, col);
   colorie(lig, col - 1);
   colorie(lig + 1, col);
   colorie(lig, col + 1);
}

signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> nbLigs >> nbCols;
   
   for(int iLig = 0;iLig < nbLigs;iLig++) {
      cin >> terrain[iLig];
   }
   
   int nbLigLibres = 0;
   for(int iLig = 0;iLig < nbLigs;iLig++) {
      char derCar = '.';
      
      int nbFois = 0;
      for(int iCol = 0;iCol < nbCols;iCol++) {
         if(terrain[iLig][iCol] == '#' && derCar == '.')
            nbFois++;
         derCar = terrain[iLig][iCol];
      }
      
      if(nbFois >= 2) {
         cout << -1 << endl;
         return 0;
      }
      
      if(nbFois == 0)
         nbLigLibres++;
   }
   
   int nbColLibres = 0;
   for(int iCol = 0;iCol < nbCols;iCol++) {
      char derCar = '.';
      
      int nbFois = 0;
      for(int iLig = 0;iLig < nbLigs;iLig++) {
         if(terrain[iLig][iCol] == '#' && derCar == '.')
            nbFois++;
         derCar = terrain[iLig][iCol];
      }
      
      if(nbFois >= 2) {
         cout << -1 << endl;
         return 0;
      }
      
      if(nbFois == 0)
         nbColLibres++;
   }
   
   int nbNords = 0;
   
   for(int iLig = 0;iLig < nbLigs;iLig++) {
      for(int iCol = 0;iCol < nbCols;iCol++) {
         if(terrain[iLig][iCol] == '#') {
            colorie(iLig, iCol);
            nbNords++;
         }
      }
   }
   
   if(nbColLibres == 0 && nbLigLibres != 0) {
      cout << -1 << endl;
      return 0;
   }
   if(nbColLibres != 0 && nbLigLibres == 0) {
      cout << -1 << endl;
      return 0;
   }
   
   cout << nbNords << endl;
   return 0;
}