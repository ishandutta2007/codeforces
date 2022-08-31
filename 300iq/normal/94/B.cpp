#include <iostream>
#include <math.h>
using namespace std;

int a[6][6];

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = a[v][u]=1;
    }
    bool good = false;
    bool bad = false;
    for (int k = 1; k <= 5; k++) {
      for (int i=k + 1;i<=5;i++) {
        for (int j = i + 1; j <= 5; j++) {
          if (a[i][j]&& a[i][k] && a[k][j]){
            good = true;
            
            }
                 if (!a[i][j]&& !a[i][k] && !a[k][j]){
            bad = true;
            }
          
          }
        
        }
      }
      if (!good&&!bad)
      cout << "FAIL";
    else
    cout << "WIN";
}