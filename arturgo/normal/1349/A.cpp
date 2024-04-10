#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <list>
#define int long long
using namespace std;

vector<int> vp[200 * 1000 + 1];

void decomp(int n) {
   int p = 2;
   
   while(p * p <= n) {
      int v = 0;
      while(n % p == 0) {
         v++;
         n /= p;
      }
      
      if(v != 0)
         vp[p].push_back(v);
      
      p++;
   }
   
   vp[n].push_back(1);
}

signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int nbNombres;
   cin >> nbNombres;
   
   for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
      int nombre;
      cin >> nombre;
      
      decomp(nombre);
   }
   
   int n = 1;
   for(int iPrem = 2;iPrem <= 200 * 1000;iPrem++) {
      for(int iFois = 0;iFois < 2;iFois++) {
         if((int)vp[iPrem].size() < nbNombres)
            vp[iPrem].push_back(0);
      }
      
      sort(vp[iPrem].begin(), vp[iPrem].end());
      
      int v = vp[iPrem][1];
      
      for(int i = 0;i < v;i++)
         n *= iPrem;
   }
   
   cout << n << endl;
   return 0;
}