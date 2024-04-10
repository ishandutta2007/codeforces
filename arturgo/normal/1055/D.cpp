#include <iostream>
using namespace std;

string avant[3000];
string apres[3000];

int debs[3000];
int fins[3000];

int main() {
  ios_base::sync_with_stdio(false);
  int nbChaines;
  cin >> nbChaines;

  for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
    cin >> avant[iChaine];
  }
  
  for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
    cin >> apres[iChaine];
  }

  int taille = -1;
  int premDiff = 0;
  for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
    debs[iChaine] = 3000;
    fins[iChaine] = -1;

    for(int iCar = 0;iCar < (int)avant[iChaine].size();iCar++) {
      if(avant[iChaine][iCar] != apres[iChaine][iCar]) {
	debs[iChaine] = min(debs[iChaine], iCar);
	fins[iChaine] = max(fins[iChaine], iCar);
      }
    }

    if(fins[iChaine] != -1) {
      premDiff = iChaine;
      if(fins[iChaine] - debs[iChaine] != taille) {
	if(taille != -1) {
	  cout << "NO" << endl;
	  return 0;
	}
	taille = fins[iChaine] - debs[iChaine];
      }
    }
  }

  bool avance = true;
  while(avance) {
    for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
      if(debs[iChaine] == 0)
	avance = false;
      else if(fins[iChaine] != -1) {
	if(avant[iChaine][debs[iChaine] - 1] != avant[premDiff][debs[premDiff] - 1]
	   || apres[iChaine][debs[iChaine] - 1] != apres[premDiff][debs[premDiff] - 1]) {
	  avance = false;
	}
      }
    }
    
    if(avance) {
      for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
	if(fins[iChaine] != -1) {
	  debs[iChaine]--;
	}
      }
    }
  }

  avance = true;
  while(avance) {
    for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
      if(fins[iChaine] == (int)avant[iChaine].size() - 1)
	avance = false;
      else if(fins[iChaine] != -1) {
	if(avant[iChaine][fins[iChaine] + 1] != avant[premDiff][fins[premDiff] + 1]
	   || apres[iChaine][fins[iChaine] + 1] != apres[premDiff][fins[premDiff] + 1]) {
	  avance = false;
	}
      }
    }
    
    if(avance) {
      for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
	if(fins[iChaine] != -1) {
	  fins[iChaine]++;
	}
      }
    }
  }

  string chaineDep = "";
  string chaineFin = "";

  for(int iCar = debs[premDiff] ;iCar <= fins[premDiff];iCar++) {
    chaineDep.push_back(avant[premDiff][iCar]);
    chaineFin.push_back(apres[premDiff][iCar]);
  }

  for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
    size_t pos = avant[iChaine].find(chaineDep);
    if(pos != string::npos) {
      for(int iCar = 0;iCar < (int)chaineDep.size();iCar++) {
	avant[iChaine][pos + iCar] = chaineFin[iCar];
      }
    }

    if(avant[iChaine] != apres[iChaine]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  cout << chaineDep << endl;
  cout << chaineFin << endl;
  
  return 0;
}