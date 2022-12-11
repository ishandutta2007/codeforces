#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int nbStops;
  cin >> nbStops;

  set<int> avant;
  for(int iStop = 0;iStop < nbStops;iStop++) {
    int nbStations;
    cin >> nbStations;

    set<int> apres;
    for(int iStation = 0;iStation < nbStations;iStation++) {
      int station;
      cin >> station;
      if(iStop == 0 || avant.count(station) == 1) {
	apres.insert(station);
      }
    }

    avant = apres;
  }

  for(int e : avant) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}