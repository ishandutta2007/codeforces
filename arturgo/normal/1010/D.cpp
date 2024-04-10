#pragma comment(linker, /STACK:36777216)
#include <iostream>
#include <vector>
using namespace std;

struct Noeud {
  int arg1, arg2;
  string type;

  int g, d;
  bool change;

  Noeud() { change = false; }
};

vector<Noeud> noeuds;

bool calculeValeur(int noeud) {
  Noeud& cur = noeuds[noeud];
  if(cur.type == "IN") {
    return cur.arg1;
  }
  if(cur.type == "NOT") {
    return (cur.g = !calculeValeur(cur.arg1));
  }
  
  int g = calculeValeur(cur.arg1);
  int d = calculeValeur(cur.arg2);

  cur.g = g; cur.d = d;
  
  if(cur.type == "AND") {
    return g && d;
  }
  if(cur.type == "OR") {
    return g || d;
  }
  if(cur.type == "XOR") {
    return g ^ d;
  }

  return true;
}

void calculeChangements(int noeud) {
  Noeud& cur = noeuds[noeud];
  if(cur.type == "IN") {
    cur.change = true;
    return;
  }
  if(cur.type == "NOT") {
    calculeChangements(cur.arg1);
    return;
  }

  int g = cur.g;
  int d = cur.d;
  
  if(cur.type == "AND") {
    if(g && d) {
      calculeChangements(cur.arg1);
      calculeChangements(cur.arg2);
    }
    if(g && !d) {
      calculeChangements(cur.arg2);
    }
    if(!g && d) {
      calculeChangements(cur.arg1);
    }
    return;
  }
  if(cur.type == "OR") {
    if(!g && !d) {
      calculeChangements(cur.arg1);
      calculeChangements(cur.arg2);
    }
    if(g && !d) {
      calculeChangements(cur.arg1);
    }
    if(!g && d) {
      calculeChangements(cur.arg2);
    }
    return;
  }
  if(cur.type == "XOR") {
    calculeChangements(cur.arg1);
    calculeChangements(cur.arg2);
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int nbPortes;
  cin >> nbPortes;

  vector<int> entrees;
  for(int iPorte = 0;iPorte < nbPortes;iPorte++) {
    Noeud nouv;
    cin >> nouv.type;

    if(nouv.type == "IN") {
      cin >> nouv.arg1;
      entrees.push_back(iPorte);
    }
    else if(nouv.type == "NOT") {
      cin >> nouv.arg1;
      nouv.arg1--;
    }
    else {
      cin >> nouv.arg1 >> nouv.arg2;
      nouv.arg1--;
      nouv.arg2--;
    }

    noeuds.push_back(nouv);
  }

  bool valeur = calculeValeur(0);
  calculeChangements(0);

  for(int entree = 0;entree < (int)entrees.size();entree++) {
    cout << (valeur ^ noeuds[entrees[entree]].change);
  }

  cout << endl;
  return 0;
}