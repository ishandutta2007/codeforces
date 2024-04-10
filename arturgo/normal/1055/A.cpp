#include <iostream>
using namespace std;

int etatsAller[20001];
int etatsRetour[20001];

int main() {
  ios_base::sync_with_stdio(false);
  int nbStations, alice;
  cin >> nbStations >> alice;
  alice--;

  for(int iStation = 0;iStation < nbStations;iStation++) {
    cin >> etatsAller[iStation];
  }

  int pgCommun = 0;
  for(int iStation = 0;iStation < nbStations;iStation++) {
    cin >> etatsRetour[iStation];
    if(etatsRetour[iStation] && etatsAller[iStation])
      pgCommun = iStation;
  }

  if(etatsAller[0] == 0) {
    cout << "NO" << endl;
  }
  else if(etatsAller[alice] == 1) {
    cout << "YES" << endl;
  }
  else if(etatsRetour[alice] == 1 && pgCommun > alice) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}