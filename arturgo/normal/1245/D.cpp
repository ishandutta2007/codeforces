#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {int x, y;};

struct Lien {int deb, fin; long long cost; };

bool operator < (const Lien &a, const Lien &b) {
	return a.cost < b.cost;
}

int parents[3000];
int minis[3000];
int ville[3000];
int coeffs[3000];
Point points[3000];

int Find(int a) {
	if(parents[a] == a)
		return a;
	return (parents[a] = Find(parents[a]));
}

long long dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbVilles;
	cin >> nbVilles;

	for(int iVille = 0;iVille < nbVilles;iVille++) {
		parents[iVille] = iVille;
		ville[iVille] = iVille;
		cin >> points[iVille].x >> points[iVille].y;
	}

	for(int iVille = 0;iVille < nbVilles;iVille++) {
		int cost;
		cin >> cost;
		minis[iVille] = cost;
	}

	long long coutChemins = 0;

	for(int iVille = 0;iVille < nbVilles;iVille++) {
		cin >> coeffs[iVille];
	}

	vector<Lien> liens;
	for(int iDeb = 0;iDeb < nbVilles;iDeb++) {
		for(int iFin = iDeb + 1;iFin < nbVilles;iFin++) {
			liens.push_back({iDeb, iFin, (coeffs[iDeb] + coeffs[iFin]) * (long long)(dist(points[iDeb], points[iFin]))});
		}
	}

	sort(liens.begin(), liens.end());

	vector<Lien> valides;
	for(Lien lien : liens) {
		if(Find(lien.deb) != Find(lien.fin) && (lien.cost <= minis[Find(lien.deb)] || lien.cost <= minis[Find(lien.fin)])) {
			int a = Find(lien.deb);
			int b = Find(lien.fin);

			parents[a] = b;
			if(minis[a] < minis[b])
				ville[b] = ville[a];
			minis[b] = min(minis[a], minis[b]);
			coutChemins += lien.cost;
			valides.push_back(lien);
		}
	}

	long long coutTotal = coutChemins;

	vector<int> villes;
	for(int iVille = 0;iVille < nbVilles;iVille++) {
		if(parents[iVille] == iVille) {
			coutTotal += minis[iVille];
			villes.push_back(ville[iVille]);
		}
	}

	cout << coutTotal << endl;
	cout << villes.size() << endl;

	for(int v : villes) {
		cout << v + 1 << " ";
	}
	cout << endl;

	cout << valides.size() << endl;
	for(Lien lien : valides) {
		cout << lien.deb + 1 << " " << lien.fin + 1 << endl;
	}
	return 0;
}