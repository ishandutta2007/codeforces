#include <iostream>
#include <vector>
using namespace std;

struct Sofa {
	int x1, y1, x2, y2;
	Sofa(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
};

int arbres[4][(1 << 20)];

void modif(int pos, int val, int id) {
	pos += (1 << 19);
	
	while(pos != 0) {
		arbres[id][pos] += val;
		pos /= 2;
	}
}

int getSomme(int deb, int fin, int id) {
	deb += (1 << 19);
	fin += (1 << 19);
	
	int somme = 0;
	while(deb < fin) {
		if(deb % 2 == 1) {
			somme += arbres[id][deb];
			deb++;
		}
		if(fin % 2 == 1) {
			fin--;
			somme += arbres[id][fin];
		}
		
		deb /= 2;
		fin /= 2;
	}
	
	return somme;
}

vector<Sofa> sofas;

int main() {
	int nbSofas;
	cin >> nbSofas;
	
	int n, m;
	cin >> n >> m;
	
	for(int iSofa = 0;iSofa < nbSofas;iSofa++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		sofas.push_back(Sofa(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2)));
	}
	
	for(Sofa s : sofas) {
		modif(s.x1, 1, 0);
		modif(s.x2, 1, 1);
		modif(s.y1, 1, 2);
		modif(s.y2, 1, 3);
	}
	
	int cx1, cy1, cx2, cy2;
	cin >> cx1 >> cx2 >> cy1 >> cy2;
	
	for(int iSofa = 0;iSofa < nbSofas;iSofa++) {
		Sofa s = sofas[iSofa];
		int x1 = getSomme(0, s.x2, 0);
		int x2 = getSomme(s.x1 + 1, 200 * 1000, 1);
		int y1 = getSomme(0, s.y2, 2);
		int y2 = getSomme(s.y1 + 1, 200 * 1000, 3);
		
		if(s.x1 == s.x2) {
			y1--; y2--;
		}
		else {
			x1--; x2--;
		}
		
		if(x1 == cx1 && x2 == cx2 && y1 == cy1 && y2 == cy2) {
			cout << iSofa + 1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}