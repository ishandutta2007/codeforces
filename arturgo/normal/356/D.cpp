#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

vector<pair<int, int>> sacs;

int piecesDans[100000];
int sacsDans[100000];

bitset<100000> stored[1000];

int curRoot = -1;
bitset<100000> temp[101];

int estPossible(int nbSacs, int nbPieces) {
	if(curRoot == nbSacs / 100) {
		return temp[nbSacs % 100][nbPieces];
	}

	curRoot = nbSacs / 100;
	temp[0] = stored[curRoot];

	for(int iSac = 100 * curRoot;iSac < min(100 * curRoot + 99, (int)sacs.size());iSac++) {
		temp[(iSac + 1) % 100] = temp[iSac % 100] | (temp[iSac % 100] << sacs[iSac].first);
	}
	return temp[nbSacs % 100][nbPieces];
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbSacs, nbPieces;
	cin >> nbSacs >> nbPieces;

	bitset<100000> possibles;
	possibles[0] = true;

	for(int iSac = 0;iSac < nbSacs;iSac++) {
		int nbPieces;
		cin >> nbPieces;
		sacs.push_back({nbPieces, iSac});
	}

	sort(sacs.begin(), sacs.end());

	stored[0] = possibles;
	for(int iSac = 0;iSac < nbSacs;iSac++) {
		possibles |= (possibles << sacs[iSac].first);

		if((iSac + 1) % 100 == 0) {
			stored[(iSac + 1) / 100] = possibles;
		}
	}

	if(sacs.back().first > nbPieces || !estPossible(nbSacs - 1, nbPieces - sacs.back().first) || !estPossible(nbSacs, nbPieces)) {
		cout << "-1" << endl;
		return 0;
	}

	vector<vector<pair<int, int>>> solution;

	while(!sacs.empty()) {
		pair<int, int> derSac = sacs.back();
		sacs.pop_back();

		if(derSac.first <= nbPieces && estPossible((int)sacs.size(), nbPieces - derSac.first)) {
			solution.push_back({derSac});
			nbPieces -= derSac.first;
		}
		else
			solution.back().push_back(derSac);
	}

	for(vector<pair<int, int>> pile : solution) {
		for(int iSac = 0;iSac < (int)pile.size() - 1;iSac++) {
			piecesDans[pile[iSac].second] = pile[iSac].first - pile[iSac + 1].first;
			sacsDans[pile[iSac].second] = pile[iSac + 1].second;
		}

		piecesDans[pile.back().second] = pile.back().first;
		sacsDans[pile.back().second] = -1;

		/*for(pair<int, int> sac : pile) {
			cout << "(" << sac.first << ", " << sac.second << ") ";
		}
		cout << endl;*/
	}

	for(int iSac = 0;iSac < nbSacs;iSac++) {
		cout << piecesDans[iSac] << " ";

		if(sacsDans[iSac] == -1) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << " " << sacsDans[iSac] + 1 << endl;
		}
	}


	return 0;
}