#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> occs, curOccs;
int deps, curDeps;

int elems[3000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbElems;
  cin >> nbElems;

  for(int iElem = 0;iElem < nbElems;iElem++) {
    cin >> elems[iElem];

    occs[elems[iElem]]++;
    if(occs[elems[iElem]] == 2)
      deps++;
  }

  if(deps == 0) {
    cout << 0 << endl;
    return 0;
  }

  int minTaille = nbElems;
  for(int deb = 0;deb < nbElems;deb++) {
    curOccs = occs;
    curDeps = deps;
    
    for(int fin = deb;fin < nbElems;fin++) {
      curOccs[elems[fin]]--;
      if(curOccs[elems[fin]] == 1)
	curDeps--;

      if(curDeps == 0) {
	minTaille = min(minTaille, fin - deb + 1);
	break;
      }
    }
  }

  cout << minTaille << endl;
  return 0;
}