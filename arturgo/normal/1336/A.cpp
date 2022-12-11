#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

vector<int> scores;
vector<int> voisins[300 * 1000];

int explore(int sommet, int prof, int parent = -1) {
   int nbFils = 0;
   for(int voisin : voisins[sommet]) {
      if(voisin != parent)
         nbFils += explore(voisin, prof + 1, sommet);
   }
   
   scores.push_back(prof - nbFils);
   
   return nbFils + 1;
}

signed main() {
   ios_base::sync_with_stdio(false);
   
   int nbSommets, nbIndustries;
   cin >> nbSommets >> nbIndustries;
   
   for(int iArc = 0;iArc < nbSommets - 1;iArc++) {
      int deb, fin;
      cin >> deb >> fin;
      
      voisins[deb - 1].push_back(fin - 1);
      voisins[fin - 1].push_back(deb - 1);
   }
   
   explore(0, 0);
   
   sort(scores.begin(), scores.end());
   
   int best = 0;
   
   for(int iScore = 0;iScore < nbIndustries;iScore++) {
      best += scores[nbSommets - 1 - iScore];
   }
   
   cout << best << endl;
   
   return 0;
}