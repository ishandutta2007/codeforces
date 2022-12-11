#include <iostream>
#include <vector>
#include <map>
using namespace std;

int parents[100 * 1000];
vector<int> voisins[100 * 1000];

bool contientFruit[100 * 1000];
int dates[100 * 1000], valeurs[100 * 1000];

struct Retour {
	map<int, long long> ajouts;

	Retour() {

	}

	void ajoute_fruit(int date, long long valeur) {
		auto it = ajouts.upper_bound(date);

		int reste = valeur;
		while(reste != 0 && it != ajouts.end()) {
			if(it->second >= reste) {
				it->second -= reste;
				reste = 0;
			}
			else {
				reste -= it->second;
				it = ajouts.erase(it);
			}
		}

		ajouts[date] += valeur;
	}

	long long get_valeur() {
		long long somme = 0;
		for(pair<int, long long> ajout : ajouts) {
			somme += ajout.second;
		}
		return somme;
	}
};

vector<Retour> retours;

int fusion(int a, int b) {
	if(retours[a].ajouts.size() < retours[b].ajouts.size())
		return fusion(b, a);

	for(pair<int, long long> ajout : retours[b].ajouts) {
		retours[a].ajouts[ajout.first] += ajout.second;
	}

	return a;
}

int solve(int sommet) {
	int id = retours.size();
	retours.push_back(Retour());

	for(int voisin : voisins[sommet]) {
		id = fusion(id, solve(voisin));
	}

	if(contientFruit[sommet]) {
		retours[id].ajoute_fruit(dates[sommet], valeurs[sommet]);
	}

	return id;
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbSommets, nbFruits, maxTemps;
	cin >> nbSommets >> nbFruits >> maxTemps;

	parents[0] = -1;
	for(int iSommet = 1;iSommet < nbSommets;iSommet++) {
		cin >> parents[iSommet];
		parents[iSommet]--;

		voisins[parents[iSommet]].push_back(iSommet);
	}

	for(int iFruit = 0;iFruit < nbFruits;iFruit++) {
		int sommet, date, valeur;
		cin >> sommet >> date >> valeur;

		contientFruit[sommet - 1] = true;
		dates[sommet - 1] = date;
		valeurs[sommet - 1] = valeur;
	}

	int id = solve(0);
	cout << retours[id].get_valeur() << endl;
	return 0;
}