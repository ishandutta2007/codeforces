#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_VILLES = 200 * 1000;
const int MAX_REQUETES = 200 * 1000;

struct Event {
  int x, deb, fin, type, id;
  Event(int _x = 0, int _deb = 0, int _fin = 0, int _type = 0, int _id = 0) {
    x = _x;
    deb = _deb;
    fin = _fin;
    type = _type;
    id = _id;
  }
};

bool operator < (const Event &a, const Event &b) {
  if(a.x == b.x)
    return a.type < b.type;
  return a.x < b.x;
}

int ancetres[MAX_VILLES][20];
vector<int> fils[MAX_VILLES];
vector<pair<int, int>> bus;
vector<Event> events;
int curDate = 0;
int profs[MAX_VILLES];
int entrees[MAX_VILLES], sorties[MAX_VILLES];
int melRem[MAX_VILLES][20];
int solutions[MAX_REQUETES];
int arbre[(1 << 20)];
int sommes[MAX_REQUETES];

void ajouteVal(int pos, int val) {
  pos += (1 << 19);
  while(pos != 0) {
    arbre[pos] += val;
    pos /= 2;
  }
}

int getSomme(int deb, int fin) {
  deb += (1 << 19);
  fin += (1 << 19);
  int somme = 0;
  while(deb < fin) {
    if(deb % 2 == 1) {
      somme += arbre[deb];
      deb++;
    }
    if(fin % 2 == 1) {
      fin--;
      somme += arbre[fin];
    }
    deb /= 2;
    fin /= 2;
  }
  return somme;
}

void calc_intervalles(int noeud, int prof = 0) {
  entrees[noeud] = curDate++;
  profs[noeud] = prof;
  for(int suiv : fils[noeud]) {
    calc_intervalles(suiv, prof + 1);
  }
  sorties[noeud] = curDate++;
}

int calc_melRem(int noeud) {
  int rem = profs[noeud];
  rem = min(rem, melRem[noeud][0]);
  for(int suiv : fils[noeud])
    rem = min(rem, calc_melRem(suiv));
  melRem[noeud][0] = rem;
  return rem;
}

int noeudRem(int noeud, int prof) {
  for(int puis = 19;puis >= 0;puis--)
    if(profs[ancetres[noeud][puis]] >= prof)
      noeud = ancetres[noeud][puis];
  return noeud;
}

bool est_ancetre(int a, int b) {
  return entrees[a] <= entrees[b] && sorties[b] <= sorties[a];
}

int ppac(int a, int b) {
  if(est_ancetre(a, b))
    return a;
  if(est_ancetre(b, a))
    return b;
  for(int puis = 19;puis >= 0;puis--) {
    if(!est_ancetre(ancetres[a][puis], b))
      a = ancetres[a][puis];
  }
  return ancetres[a][0];
}

pair<int, int> remMax(int noeud, int maxi) {
  int remonte = 0;
  for(int puis = 19;puis >= 0;puis--) {
    if(profs[maxi] < melRem[noeud][puis]) {
      remonte += (1 << puis);
      noeud = noeudRem(noeud, melRem[noeud][puis]);
    }
  }
  return {remonte, noeud};
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbVilles;
  cin >> nbVilles;

  melRem[0][0] = MAX_VILLES;
  for(int iVille = 1;iVille < nbVilles;iVille++) {
    int parent;
    cin >> parent;
    ancetres[iVille][0] = parent - 1;
    fils[parent - 1].push_back(iVille);
    melRem[iVille][0] = MAX_VILLES;
  }

  calc_intervalles(0);
  for(int puis = 1;puis < 20;puis++) {
    for(int ville = 0;ville < nbVilles;ville++) {
      ancetres[ville][puis] = ancetres[ancetres[ville][puis - 1]][puis - 1];
    }
  }
  
  int nbBus;
  cin >> nbBus;

  for(int iBus = 0;iBus < nbBus;iBus++) {
    int deb, fin;
    cin >> deb >> fin;
    bus.push_back({deb - 1, fin - 1});
    int mel = ppac(deb - 1, fin - 1);
    melRem[deb - 1][0] = min(melRem[deb - 1][0], profs[mel]);
    melRem[fin - 1][0] = min(melRem[fin - 1][0], profs[mel]);
    events.push_back(Event(entrees[deb - 1], entrees[fin - 1], 0, 2, -1));
    events.push_back(Event(entrees[fin - 1], entrees[deb - 1], 0, 2, -1));
  }
  calc_melRem(0);

  for(int iNoeud = 0;iNoeud < nbVilles;iNoeud++) {
    for(int puis = 1;puis < 20;puis++) {
      melRem[iNoeud][puis] = melRem[noeudRem(iNoeud, melRem[iNoeud][puis - 1])][puis - 1];
    }
  }
  
  int nbReqs;
  cin >> nbReqs;

  
  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int deb, fin;
    cin >> deb >> fin;
    deb--; fin--;

    if(deb == fin) {
      cout << 0 << endl;
      continue;
    }
    
    int haut = ppac(deb, fin);
    if(melRem[deb][19] > profs[haut] || melRem[fin][19] > profs[haut]) {
      solutions[iReq] = -1;
      continue;
    }

    if(haut == deb) {
      pair<int, int> lfin = remMax(fin, haut);
      solutions[iReq] = lfin.first + 1;
      continue;
    }
    if(haut == fin) {
      pair<int, int> ldeb = remMax(deb, haut);
      solutions[iReq] = ldeb.first + 1;
      continue;
    }
    
    pair<int, int> ldeb = remMax(deb, haut);
    pair<int, int> lfin = remMax(fin, haut);

    solutions[iReq] = ldeb.first + lfin.first + 2;

    events.push_back(Event(entrees[ldeb.second], entrees[lfin.second], sorties[lfin.second], 0, iReq));
    events.push_back(Event(sorties[ldeb.second], entrees[lfin.second], sorties[lfin.second], 1, iReq));
  }

  sort(events.begin(), events.end());

  for(Event event : events) {
    if(event.type == 2) {
      ajouteVal(event.deb, 1);
    }
    else if(event.type == 1) {
      int curSomme = getSomme(event.deb, event.fin);
      if(sommes[event.id] != curSomme)
	solutions[event.id]--;
    }
    else if(event.type == 0) {
      sommes[event.id] = getSomme(event.deb, event.fin);
    }
  }

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    cout << solutions[iReq] << endl;
  }
  return 0;
}