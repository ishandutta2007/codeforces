#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#define int long long
using namespace std;

struct Rect {
	int x1, y1, x2, y2;
};

const int INFINI = 2000ll * 1000 * 1000;

const int SOURCE = 0;
const int LEFT = 1;
const int RIGHT = 10000;
const int PUITS = 20001;

vector<pair<int, int>> arcs;
vector<pair<int, int>> voisins[30000];

int curPasse = 0;
int derPasse[30000];

bool ameliore(int noeud, int taille) {
	if(derPasse[noeud] == curPasse)
		return false;
	derPasse[noeud] = curPasse;

	if(noeud == PUITS)
		return true;

	for(pair<int, int> voisin : voisins[noeud]) {
		if(arcs[voisin.second].first >= taille && ameliore(voisin.first, taille)) {
			arcs[voisin.second].first -= taille;
			arcs[arcs[voisin.second].second].first += taille;
			return true;
		}
	}
	return false;
}

void ajouteArc(int deb, int fin, int val) {
	int id = arcs.size();
	int rid = id + 1;

	arcs.push_back({val, rid});
	arcs.push_back({0, id});
	voisins[deb].push_back({fin, id});
	voisins[fin].push_back({deb, rid});
}

signed main() {
	ios_base::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	int taille, nbRects;
	cin >> taille >> nbRects;

	vector<Rect> rects;

	map<int, int> xs, ys;

	for(int iRect = 0;iRect < nbRects;iRect++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--;
		rects.push_back({x1, y1, x2, y2});
		xs[x1] = 0;
		xs[x2] = 0;
		ys[y1] = 0;
		ys[y2] = 0;
	}

	int iX = 0;
	for(auto it = xs.begin();it != xs.end();it++) {
		it->second = iX++;
	}

	int iY = 0;
	for(auto it = ys.begin();it != ys.end();it++) {
		it->second = iY++;
	}

	for(Rect r : rects) {
		auto iX = xs.lower_bound(r.x1);
		vector<int> idXs;
		while(iX->first != r.x2) {
			idXs.push_back(iX->second);
			iX++;
		}

		auto iY = ys.lower_bound(r.y1);
		vector<int> idYs;
		while(iY->first != r.y2) {
			idYs.push_back(iY->second);
			iY++;
		}

		for(int x : idXs) {
			for(int y : idYs) {
				ajouteArc(RIGHT + x, LEFT + y, INFINI);
			}
		}
	}

	for(auto it = xs.begin();it != xs.end();it++) {
		auto n = it; n++;
		ajouteArc(SOURCE, RIGHT + it->second, n->first - it->first);
	}

	for(auto it = ys.begin();it != ys.end();it++) {
		auto n = it; n++;
		ajouteArc(LEFT + it->second, PUITS, n->first - it->first);
	}

	int val = (1 << 30);
	long long flot = 0;

	while(val != 0) {
		curPasse++;
		while(ameliore(SOURCE, val)) {
			flot += val;
			curPasse++;
		}
		val /= 2;
	}

	cout << flot << endl;

	return 0;
}