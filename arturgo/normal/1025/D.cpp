#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nombres[1000];

int pgcds[1000][1000];

int pgcd(int a, int b) {
  if(a == 0)
    return b;
  return pgcd(b % a, a);
}

bool dyn[2][800][800];
bool estPasse[2][800][800];

bool solve(int deb, int fin, bool cote) {
  if(deb == fin)
    return true;

  if(estPasse[cote][deb][fin])
    return dyn[cote][deb][fin];
  estPasse[cote][deb][fin] = true;

  bool ans = false;
  for(int pivot = deb;pivot < fin;pivot++) {
    if(cote) {
      if(pgcds[pivot][fin] == 1)
	continue;
    }
    else {
      if(pgcds[pivot][deb - 1] == 1)
	continue;
    }
    
    if(solve(deb, pivot, true) && solve(pivot + 1, fin, false)) {
      ans = true;
      break;
    }
  }

  dyn[cote][deb][fin] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbElems;
  cin >> nbElems;

  for(int iElem = 0;iElem < nbElems;iElem++) {
    cin >> nombres[iElem];
  }

  for(int iA = 0;iA < nbElems;iA++) {
    for(int iB = 0;iB < nbElems;iB++) {
      pgcds[iA][iB] = pgcd(nombres[iA], nombres[iB]);
    }
  }
  for(int pivot = 0;pivot < nbElems;pivot++) {
    if(solve(0, pivot, true) && solve(pivot + 1, nbElems, false)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}