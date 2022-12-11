#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

deque<int> nombres;

int nombreA[300 * 1000];
int nombreB[300 * 1000];

vector<pair<long long, int>> reqs;

int32_t main() {
  ios_base::sync_with_stdio(false);
  int nbNombres, nbReqs;
  cin >> nbNombres >> nbReqs;

  int maxi = 0;
  for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
    int nombre;
    cin >> nombre;
    nombres.push_back(nombre);

    maxi = max(maxi, nombre);
  }

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    long long tour;
    cin >> tour;
    reqs.push_back({tour, iReq});
  }

  sort(reqs.begin(), reqs.end());
  int curReq = 0;

  int iTour = 1;
  while(nombres[0] != maxi) {
    int A = nombres.front(); nombres.pop_front();
    int B = nombres.front(); nombres.pop_front();
    
    while(curReq < nbReqs && iTour == reqs[curReq].first) {
      nombreA[reqs[curReq].second] = A;
      nombreB[reqs[curReq].second] = B;
      curReq++;
    }

    if(A > B) {
      nombres.push_front(A);
      nombres.push_back(B);
    }
    else {
      nombres.push_back(A);
      nombres.push_front(B);
    }
    
    iTour++;
  }
  
  for(;curReq < nbReqs;curReq++) {
    int tour = reqs[curReq].first;
    nombreA[reqs[curReq].second] = maxi;
    nombreB[reqs[curReq].second] = nombres[1 + (tour - iTour) % (nbNombres - 1)];
  }

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    cout << nombreA[iReq] << " " << nombreB[iReq] << endl;
  }
  
  return 0;
}