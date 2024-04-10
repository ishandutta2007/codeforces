#include <iostream>
using namespace std;

struct Noeud {
  int occs[3];
  int types[3][3][3];

  void reset() {
    occs[0] = occs[1] = occs[2] = 0;

    for(int type = 0;type < 3;type++) {
      for(int gauche = 0;gauche < 3;gauche++) {
	for(int droite = 0;droite < 3;droite++) {
	  types[type][gauche][droite] = 0;
	}
      }
    }
  }
  
  Noeud(int id) {
    reset();

    occs[id]++;
    types[id][0][0]++;
  }

  Noeud() {
    reset();
  }
};

Noeud arbre[(1 << 19)];
int tr[256];

Noeud fusion(Noeud a, Noeud b) {
  Noeud retour = Noeud();
  for(int i = 0;i < 3;i++) {
    retour.occs[i] = a.occs[i] + b.occs[i];
  }

  //a
  for(int type = 0;type < 3;type++) {
    for(int gauche = 0;gauche < 3;gauche++) {
      retour.types[type][gauche][2] += a.types[type][gauche][2];
      
      if(b.occs[(type + 2) % 3] != 0) {
	retour.types[type][gauche][2] += a.types[type][gauche][0];
	retour.types[type][gauche][2] += a.types[type][gauche][1];
      }
      else if(b.occs[(type + 1) % 3] != 0) {
	retour.types[type][gauche][1] += a.types[type][gauche][0];
        retour.types[type][gauche][1] += a.types[type][gauche][1];
      }
      else {
	retour.types[type][gauche][0] += a.types[type][gauche][0];
	retour.types[type][gauche][1] += a.types[type][gauche][1];
      }
    }
  }

  //b
  for(int type = 0;type < 3;type++) {
    for(int droite = 0;droite < 3;droite++) {
      retour.types[type][2][droite] += b.types[type][2][droite];
      
      if(a.occs[(type + 2) % 3] != 0) {
	retour.types[type][2][droite] += b.types[type][0][droite];
	retour.types[type][2][droite] += b.types[type][1][droite];
      }
      else if(a.occs[(type + 1) % 3] != 0) {
	retour.types[type][1][droite] += b.types[type][0][droite];
        retour.types[type][1][droite] += b.types[type][1][droite];
      }
      else {
	retour.types[type][0][droite] += b.types[type][0][droite];
	retour.types[type][1][droite] += b.types[type][1][droite];
      }
    }
  }
  return retour;
}

void modifie(int pos, Noeud val) {
  pos += (1 << 18);

  arbre[pos] = val;

  while(pos != 1) {
    pos /= 2;
    arbre[pos] = fusion(arbre[2 * pos], arbre[2 * pos + 1]);
  }
}

void affiche() {
  int somme = 0;

  for(int type = 0;type < 3;type++) {
    for(int gauche = 0;gauche < 3;gauche += 2) {
      for(int droite = 0;droite < 3;droite += 2) {
	somme += arbre[1].types[type][gauche][droite];
      }
    }
  }
  cout << somme << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int nbJoueurs, nbReqs;
  cin >> nbJoueurs >> nbReqs;

  tr[(int)'R'] = 0;
  tr[(int)'P'] = 1;
  tr[(int)'S'] = 2;

  for(int iJoueur = 0;iJoueur < nbJoueurs;iJoueur++) {
    char symbole;
    cin >> symbole;
    modifie(iJoueur, Noeud(tr[(int)symbole]));
  }

  affiche();

  for(int iReq = 0;iReq < nbReqs;iReq++) {
    int pos;
    char symbole;
    cin >> pos >> symbole;
    pos--;
    modifie(pos, Noeud(tr[(int)symbole]));

    affiche();
  }
  return 0;
}