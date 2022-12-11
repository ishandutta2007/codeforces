#include <iostream>
#include <vector>
#define int long long

using namespace std;

vector<int> voisins[300 * 1000];
vector<int> r_voisins[300 * 1000];
int nbParents[300 * 1000];

int numero[300 * 1000];

int minId[300 * 1000];
int minIdR[300 * 1000];

int nbForalls = 0;

signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int nbVars, nbIneq;
   cin >> nbVars >> nbIneq;
   
   for(int iIneq = 0;iIneq < nbIneq;iIneq++) {
      int deb, fin;
      cin >> deb >> fin;
      
      voisins[deb - 1].push_back(fin - 1);
      r_voisins[fin - 1].push_back(deb - 1);
      
      nbParents[fin - 1]++;
   }
   
   vector<int> pile;
   for(int iVar = 0;iVar < nbVars;iVar++) {
      if(nbParents[iVar] == 0)
         pile.push_back(iVar);
   }
   
   vector<int> ordre;
   
   for(int iVar = 0;iVar < nbVars;iVar++) {
      minId[iVar] = iVar;
      minIdR[iVar] = iVar;
      
      while(!pile.empty() && numero[pile.back()] != 0)
         pile.pop_back();
      
      if(pile.empty()) {
         cout << -1 << endl;
         return 0;
      }
      
      numero[pile.back()] = iVar + 1;
      ordre.push_back(pile.back());
      
      for(int voisin : voisins[pile.back()]) {
         nbParents[voisin]--;
         if(nbParents[voisin] == 0)
            pile.push_back(voisin);
      }
   }
   
   for(int iVar = 0;iVar < nbVars;iVar++) {
      int var = ordre[iVar];
      
      for(int voisin : r_voisins[var]) {
         minIdR[var] = min(minIdR[var], minIdR[voisin]);
      }
   }
   
   for(int iVar = nbVars - 1;iVar >= 0;iVar--) {
      int var = ordre[iVar];
      
      for(int voisin : voisins[var]) {
         minId[var] = min(minId[var], minId[voisin]);
      }
   }
   
   for(int iVar = 0;iVar < nbVars;iVar++) {
      if(minId[iVar] >= iVar && minIdR[iVar] >= iVar) {
         nbForalls++;
      }
   }
   
   cout << nbForalls << endl;
   
   for(int iVar = 0;iVar < nbVars;iVar++) {
      if(minId[iVar] >= iVar && minIdR[iVar] >= iVar) {
         cout << "A";
      }
      else {
         cout << "E";
      }
   }
   cout << endl;
   return 0;
}