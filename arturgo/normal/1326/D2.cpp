#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string intercale(string chaine) {
	string res = "";
	for(char c : chaine) {
		res.push_back(c);
		res.push_back('#');
	}
	return res;
}

int plusLongPalinDeb(string chaine) {
	if(chaine.size() <= 1)
		return chaine.size();

	chaine = intercale(chaine);

	vector<int> reponses;
	reponses.push_back(1);

	int milieu = 0, gauche = 1;

	for(int i = 1;i < (int)chaine.size();i++) {
		int ngauche = i;
		if(i < gauche) {
			ngauche = i + max(0, min(reponses[2 * milieu - i] - 1, gauche - i - 1));
		}

		while(ngauche < (int)chaine.size() && 2 * i - ngauche >= 0 && chaine[ngauche] == chaine[2 * i - ngauche]) {
			ngauche++;
		}

		reponses.push_back(ngauche - i);

		if(ngauche > gauche) {
			gauche = ngauche;
			milieu = i;
		}
	}

	int maxi = 1;

	for(int i = 0;i < (int)chaine.size();i++) {
		if(reponses[i] == i + 1) {
			maxi = max(maxi, reponses[i]);
		}
	}

	return maxi;
}

string reversed(string chaine) {
	reverse(chaine.begin(), chaine.end());
	return chaine;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nbTests;
	cin >> nbTests;

	for(int iTest = 0;iTest < nbTests;iTest++) {
		string chaine;
		cin >> chaine;

		int taille = 0;
		while(2 * (taille + 1) <= (int)chaine.size() && chaine[taille] == chaine[chaine.size() - taille - 1]) {
			taille++;
		}

		string milieu, rmilieu;

		for(int i = taille;i < (int)chaine.size() - taille;i++) {
			milieu.push_back(chaine[i]);
		}
		rmilieu = reversed(milieu);

		int gauche = plusLongPalinDeb(milieu);
		int droite = plusLongPalinDeb(rmilieu);

		string res;
		for(int i = 0;i < taille;i++)
			res.push_back(chaine[i]);

		if(gauche < droite) {
			for(int i = 0;i < droite;i++)
				res.push_back(rmilieu[i]);
		}
		else {
			for(int i = 0;i < gauche;i++)
				res.push_back(milieu[i]);
		}

		for(int i = 0;i < taille;i++) {
			res.push_back(chaine[chaine.size() - taille + i]);
		}

		cout << res << endl;
	}

	return 0;
}