#include <iostream>
#include <vector>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;

int curPasse = 0;
int derPasse[40 * 1000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbTests;
  cin >> nbTests;

  for(int iTest = 0;iTest < nbTests;iTest++) {
    int n, m, k;
    cin >> n >> m >> k;

    string chaine;
    cin >> chaine;

    vector<int> occs(26, 0);

    for(char lettre : chaine) {
      occs[lettre - 'A']++;
    }
    
    int minCout = INFINI;
    for(int iPivot = 0;iPivot < 26;iPivot++) {
      curPasse++;
      derPasse[0] = curPasse;
      for(int iLettre = 0;iLettre < 26;iLettre++) {
	if(iPivot != iLettre) {
	  for(int iGauche = n - occs[iLettre];iGauche >= 0;iGauche--) {
	    if(derPasse[iGauche] == curPasse) {
	      derPasse[iGauche + occs[iLettre]] = curPasse;
	    }
	  }
	}
      }

      for(int iGauche = 0;iGauche <= n;iGauche++) {
	if(derPasse[iGauche] == curPasse) {
	  int iDroite = k - iGauche - occs[iPivot];
	  if(max(0, n - iGauche) + max(0, m - iDroite) <= occs[iPivot]) {
	    minCout = min(minCout, max(0, n - iGauche) * max(0, m - iDroite));
	  }
	}
      }
    }
    cout << minCout << endl << endl;
  }
  return 0;
}