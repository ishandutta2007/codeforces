#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

const long long INFINI = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000ll;

struct Event {
   int lig, col, dist;
};

string terrain[1000];

int nbLigs, nbCols, nbReqs;
long long dists[1000][1000];

int dirs[4][2] = {
   {1, 0},
   {0, 1},
   {0, -1},
   {-1, 0}
};

bool estValide(int l, int c) {
   return l >= 0 && c >= 0 && l < nbLigs && c < nbCols;
}

int d = 0, f = 0;

Event events[4000 * 1000];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> nbLigs >> nbCols >> nbReqs;
   
   for(int iLig = 0;iLig < nbLigs;iLig++) {
      cin >> terrain[iLig];  
   }
   
   for(int iLig = 0;iLig < nbLigs;iLig++) {
      for(int iCol = 0;iCol < nbCols;iCol++) {
         bool estV = false;
         dists[iLig][iCol] = INFINI;
         
         for(int iDir = 0;iDir < 4;iDir++) {
            int nLig = iLig + dirs[iDir][0];
            int nCol = iCol + dirs[iDir][1];
            
            if(estValide(nLig, nCol) && terrain[nLig][nCol] == terrain[iLig][iCol]) {
               estV = true;
            }
         }
         
         if(estV) {
            events[f++] = {iLig, iCol, 0};
            dists[iLig][iCol] = 0;
         }
      }
   }
   
   while(d != f) {
      Event cur = events[d++];
      
      dists[cur.lig][cur.col] = min(dists[cur.lig][cur.col], (long long)cur.dist);
      
      for(int iDir = 0;iDir < 4;iDir++) {
         int nLig = cur.lig + dirs[iDir][0];
         int nCol = cur.col + dirs[iDir][1];
         
         if(estValide(nLig, nCol) && dists[nLig][nCol] == INFINI) {
            events[f++] = {nLig, nCol, cur.dist + 1};
            
            dists[nLig][nCol] = cur.dist + 1;
         }
      }
   }
   
   for(int iReq = 0;iReq < nbReqs;iReq++) {
      int lig, col;
      long long t;
      cin >> lig >> col >> t;
      
      lig--;
      col--;
      
      if(t <= dists[lig][col]) {
         cout << terrain[lig][col] << endl;
      }
      else {
         cout << ((long long)(terrain[lig][col] - '0') + t - dists[lig][col]) % 2 << endl;
      }
   }
   return 0;
}