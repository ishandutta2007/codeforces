#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Domino {
	int pos, hauteur, id;
};

bool operator < (const Domino& a, const Domino& b) {
	return a.pos < b.pos;
}

vector<Domino> dominos;
int nbTombe[100 * 1000];

int main() {
	ios_base::sync_with_stdio(false);
	int nbDominos;
	cin >> nbDominos;

	for(int iDomino = 0;iDomino < nbDominos;iDomino++) {
		int pos, hauteur;
		cin >> pos >> hauteur;
		dominos.push_back({pos, hauteur, iDomino});
	}

	sort(dominos.begin(), dominos.end());
	reverse(dominos.begin(), dominos.end());

	vector<pair<int, int>> results;

	for(Domino domino : dominos) {
		int maxTombe = 0;

		while(!results.empty() && results.back().first < domino.pos + domino.hauteur) {
			maxTombe += results.back().second;
			results.pop_back();
		}

		nbTombe[domino.id] = maxTombe + 1;
		results.push_back({domino.pos, maxTombe + 1});
	}

	for(int iDomino = 0;iDomino < nbDominos;iDomino++) {
		cout << nbTombe[iDomino] << " ";
	}
	cout << endl;
	return 0;
}