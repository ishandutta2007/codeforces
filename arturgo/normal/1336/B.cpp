#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;

const int INFINI = 2000ll * 1000 * 1000 * 1000 * 1000 * 1000ll;

set<int> values[3];

void getValue(int t) {
   int v;
   cin >> v;
   values[t].insert(v);
}

int carre(int x) { return x * x; }

int teste(int m, int pg, int pp) {
   int mini = INFINI;
   for(int v : values[m]) {
      auto it_pg = values[pg].lower_bound(v);
      if(it_pg == values[pg].end()) continue;
      
      auto it_pp = values[pp].upper_bound(v);
      if(it_pp == values[pp].begin()) continue;
      it_pp--;
      
      mini = min(mini, carre(*it_pg - v) + carre(*it_pp - v) + carre(*it_pp - *it_pg));
   }
   return mini;
}

signed main() {
   ios_base::sync_with_stdio(false);
   
   int nbTests;
   cin >> nbTests;
   
   for(int iTest = 0;iTest < nbTests;iTest++) {
      int nbR, nbG, nbB;
      cin >> nbR >> nbG >> nbB;
      
      for(int iR = 0;iR < nbR;iR++) {
         getValue(0);
      }
      
      for(int iG = 0;iG < nbG;iG++) {
         getValue(1);
      }
      
      for(int iB = 0;iB < nbB;iB++) {
         getValue(2);
      }
      
      int mini = INFINI;
      for(int iC = 0;iC < 3;iC++) {
         mini = min(mini, teste(iC, (iC + 1) % 3, (iC + 2) % 3));
         mini = min(mini, teste(iC, (iC + 2) % 3, (iC + 1) % 3));
      }
      
      cout << mini << endl;
      
      for(int iC = 0;iC < 3;iC++)
         values[iC].clear();
   }
   
   return 0;
}