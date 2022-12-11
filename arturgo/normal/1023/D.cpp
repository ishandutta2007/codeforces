#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> elems;

bool change_zero(int maxi) {
  for(int& elem : elems) {
    if(elem == 0) {
      elem = maxi;
      return true;
    }
  }
  return false;
}

bool opened[500 * 1000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbElems, nbReqs;
  cin >> nbElems >> nbReqs;

  int maxi = 0;

  for(int iElem = 0;iElem < nbElems;iElem++) {
    int elem;
    cin >> elem;
    elems.push_back(elem);
    maxi = max(maxi, elem);
  }

  if(maxi != nbReqs) {
    if(!change_zero(nbReqs)) {
      cout << "NO" << endl;
      return 0;
    }
  }

  vector<int> seq;
  vector<int> pile;
  for(int iElem = 0;iElem < nbElems;iElem++) {
    if(elems[iElem] == 0) {
      if(!pile.empty())
	seq.push_back(pile.back());
      else
	seq.push_back(1);
    }
    else {
      seq.push_back(elems[iElem]);

      while(!pile.empty() && pile.back() > elems[iElem])
	pile.pop_back();

      if(opened[elems[iElem]]) {
	if(pile.empty() || pile.back() != elems[iElem]) {
	  cout << "NO" << endl;
	  return 0;
	}
      }
      else {
	opened[elems[iElem]] = true;
	pile.push_back(elems[iElem]);
      }
    }
  }

  cout << "YES" << endl;

  for(int iElem = 0;iElem < nbElems;iElem++) {
    cout << seq[iElem] << " ";
  }
  cout << endl;
  return 0;
}