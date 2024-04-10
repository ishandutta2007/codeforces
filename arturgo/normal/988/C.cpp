#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Somme {
  int seq, elem, somme;
  Somme(int _seq = 0, int _elem = 0, int _somme = 0) {
    seq = _seq;
    elem = _elem;
    somme = _somme;
  }
};

bool operator < (const Somme &a, const Somme &b) {
  return a.somme < b.somme;
}

vector<Somme> sommes;

int main() {
  int nbSeqs;
  cin >> nbSeqs;

  for(int iSeq = 0;iSeq < nbSeqs;iSeq++) {
    int nbElems;
    cin >> nbElems;

    int somme = 0;
    vector<int> seq;
    for(int iElem = 0;iElem < nbElems;iElem++) {
      int elem;
      cin >> elem;
      seq.push_back(elem);
      somme += elem;
    }

    for(int iElem = 0;iElem < nbElems;iElem++) {
      sommes.push_back(Somme(iSeq, iElem, somme - seq[iElem]));
    }
  }

  sort(sommes.begin(), sommes.end());

  for(int iSomme = 1;iSomme < (int)sommes.size();iSomme++) {
    if(sommes[iSomme - 1].seq != sommes[iSomme].seq && sommes[iSomme - 1].somme == sommes[iSomme].somme) {
      cout << "YES" << endl;
      cout << sommes[iSomme].seq + 1 << " " << sommes[iSomme].elem + 1 << endl;
      cout << sommes[iSomme - 1].seq + 1 << " " << sommes[iSomme - 1].elem + 1 << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}