#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

int nbCars, nbFlips;

struct Inter {
  int deb, fin, couleur;

  Inter(int _deb = 0, int _fin = 0, int _couleur = 0) {
    deb = _deb;
    fin = _fin;
    couleur = _couleur;
  }

  int taille() {
    return fin - deb;
  }
};

bool operator < (const Inter& a, const Inter &b) {
  return a.fin < b.fin;
}

struct Game {
  set<Inter> inters;

  bool peutOS() {
    if(inters.size() <= 1)
      return true;

    Inter deb = *inters.begin();
    Inter fin = *inters.rbegin();

    if(nbCars - max(fin.taille(), deb.taille()) <= nbFlips)
      return true;
    
    if(deb.couleur == fin.couleur && nbCars - (fin.taille() + deb.taille()) <= nbFlips)
      return true;

    return false;
  }

  void merge(set<Inter>::iterator mil) {
    auto fin = mil; fin++;
    if(fin != inters.end()) {
      if(fin->couleur == mil->couleur) {
	Inter nouv = *mil;	
	nouv.fin = fin->fin;
	inters.erase(mil);
	inters.erase(fin);
	mil = inters.insert(nouv).first;
      }
    }
    
    if(mil != inters.begin()) {
      auto deb = mil; deb--;
      if(deb->couleur == mil->couleur) {
	Inter nouv = *deb;
	nouv.fin = mil->fin;
	inters.erase(mil);
	inters.erase(deb);
	mil = inters.insert(nouv).first;
      }
    }
  }
  
  void change(int pos, int val) {
    Inter inter(pos, pos + 1, val);

    auto it = inters.lower_bound(inter);
    assert(it != inters.end());

    Inter gauche = *it;
    inters.erase(it);

    Inter droite = gauche;
    droite.deb = pos + 1;
    gauche.fin = pos;

    if(droite.taille() != 0)
      inters.insert(droite);
    if(gauche.taille() != 0)
      inters.insert(gauche);
    
    auto d = inters.insert(inter).first;

    merge(d);
  }
  
  Game(string chaine) {
    inters.insert(Inter(0, nbCars, 0));

    for(int iPos = 0;iPos < nbCars;iPos++) {
      change(iPos, chaine[iPos] - '0');
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin >> nbCars >> nbFlips;

  string chaine;
  cin >> chaine;

  Game game(chaine);
  if(game.peutOS()) {
    cout << "tokitsukaze" << endl;
    return 0;
  }

  for(int pos = 0;pos < nbCars;pos++) {
    game.change(pos, 0);
    if(pos >= nbFlips - 1) {
      if(!game.peutOS()) {
	cout << "once again" << endl;
	return 0;
      }
      game.change(pos - nbFlips + 1, chaine[pos - nbFlips + 1] - '0');
    }
  }

  game = Game(chaine);

  for(int pos = 0;pos < nbCars;pos++) {
    game.change(pos, 1);
    if(pos >= nbFlips - 1) {
      if(!game.peutOS()) {
	cout << "once again" << endl;
	return 0;
      }
      game.change(pos - nbFlips + 1, chaine[pos - nbFlips + 1] - '0');
    }
  }

  cout << "quailty" << endl;
  return 0;
}