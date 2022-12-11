#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long cyclicHash[2000 * 1000 + 1];
long long p37[2000 * 1000 + 1];
const int MOD = 1000 * 1000 * 1000 + 7;

long long h(int a, int b) {
  return (p37[2000 * 1000 - a] * (cyclicHash[b] - cyclicHash[a] + MOD)) % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;

  p37[0] = 1;
  for(int i = 1;i <= 2000 * 1000;i++) {
    p37[i] = (p37[i - 1] * 37) % MOD;
  }

  for(int iCar = 0;iCar < (int)t.size();iCar++) {
    cyclicHash[iCar + 1] = (cyclicHash[iCar] + p37[iCar] * (int)(t[iCar] - 'a' + 1)) % MOD;
  }

  int nb0s = 0, nb1s = 0;

  for(char bit : s) {
    if(bit == '0')
      nb0s++;
    else
      nb1s++;
  }
  
  int nbValides = 0;
  for(int taille_0 = 1;taille_0 < (int)t.size();taille_0++) {
    int reste = (int)t.size() - taille_0 * nb0s;
    if(reste <= 0) {
      break;
    }
    if(reste % nb1s != 0)
      continue;

    int taille_1 = reste / nb1s;

    int der0 = -1;
    int der1 = -1;
    int curIndex = 0;
    bool estValide = true;

    for(char bit : s) {
      if(bit == '0') {
	if(der0 != -1) {
	  if(h(der0, der0 + taille_0) != h(curIndex, curIndex + taille_0)) {
	    estValide = false;
	    break;
	  }
	}
	der0 = curIndex;
	curIndex += taille_0;
      }
      else {
	if(der1 != -1) {
	  if(h(der1, der1 + taille_1) != h(curIndex, curIndex + taille_1)) {
	    estValide = false;
	    break;
	  }
	}
	der1 = curIndex;
	curIndex += taille_1;
      }
    }

    if(der0 != -1 && der1 != -1 && h(der1, der1 + taille_1) == h(der0, der0 + taille_0))
      estValide = false;

    if(estValide)
      nbValides++;
  }

  cout << nbValides << endl;
  
  return 0;
}