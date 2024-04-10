#include <iostream>
#define int long long

using namespace std;

int curPasse = 0;
int derPasse[300 * 1000];

int MOD(int a, int b) {
   return ((a % b) + b) % b;
}

signed main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int nbTests;
   cin >> nbTests;
   
   for(int iTest = 0;iTest < nbTests;iTest++) {
      int taille;
      cin >> taille;
      
      curPasse++;
      bool valide = true;
      for(int i = 0;i < taille;i++) {
         int nombre;
         cin >> nombre;
         
         int pos = MOD(nombre + i, taille);
         
         if(derPasse[pos] == curPasse)
            valide = false;
         derPasse[pos] = curPasse;
      }
      
      if(valide)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
   return 0;
}