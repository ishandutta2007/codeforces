#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>
#include <cstdio>
#include <map>
#include <cstdio>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

int deps[8][2] = {
	{1, 0},
	{1, 1},
	{0, 1},
	{-1, 1},
	{-1, 0},
	{-1, -1},
	{0, -1},
	{1, -1}
};

struct Info {
	bool estPasse;
	int zone;
	int id;

	Info(int _id = -1) {
		id = _id;
		estPasse = false;
		zone = -1;
	}
};

vector<pair<int, int>> points;

const int MOD = 1000 * 1000 + 33;
vector<pair<pair<int, int>, Info>> infos[MOD];

inline Info& getInfo(pair<int, int> coord) {
	int h = (MOD + (coord.first + 31ll * coord.second) % MOD) % MOD;

	for(pair<pair<int, int>, Info>& paire : infos[h]) {
		if(paire.first == coord)
			return paire.second;
	}

	infos[h].push_back({coord, Info()});
	return infos[h].back().second;
}

inline bool existInfo(pair<int, int> coord) {
	int h = (MOD + (coord.first + 31ll * coord.second) % MOD) % MOD;

	for(pair<pair<int, int>, Info>& paire : infos[h]) {
		if(paire.first == coord)
			return true;
	}

	return false;
}

int arbre[(1 << 19)];

inline void setVal(int pos, int val) {
	pos += (1 << 18);
	arbre[pos] = val;

	while(pos != 1) {
		pos /= 2;
		arbre[pos] = max(arbre[2 * pos], arbre[2 * pos + 1]);
	}
}

inline int zone(int lig, int col) {
	if(getInfo({lig, col}).zone == -1)
		return -1 - getInfo({lig, col}).id;
	return getInfo({lig, col}).zone;
}

inline bool estPoint(int lig, int col) {
	return getInfo({lig, col}).id != -1;
}

inline void update(pair<int, int> coord) {
	if(!existInfo(coord))
		return;
	if(getInfo(coord).id == -1)
		return;

	bool toucheInf = false;
	for(int iDep = 0;iDep < 4;iDep++) {
		if(zone(coord.first + deps[2 * iDep][0], coord.second + deps[2 * iDep][1]) == 0)
			toucheInf = true;
	}

	bool connecte = true;

	bool pointBas = estPoint(coord.first + 1, coord.second + 1) || estPoint(coord.first + 1, coord.second) || estPoint(coord.first + 1, coord.second - 1);
	bool pointHaut = estPoint(coord.first - 1, coord.second + 1) || estPoint(coord.first - 1, coord.second) || estPoint(coord.first - 1, coord.second - 1);
	bool pointDroite = estPoint(coord.first + 1, coord.second + 1) || estPoint(coord.first, coord.second + 1) || estPoint(coord.first - 1, coord.second + 1);
	bool pointGauche = estPoint(coord.first + 1, coord.second - 1) || estPoint(coord.first, coord.second - 1) || estPoint(coord.first - 1, coord.second - 1);

	if(zone(coord.first + 1, coord.second) == zone(coord.first - 1, coord.second) && pointDroite && pointGauche)
		connecte = false;
	if(zone(coord.first, coord.second + 1) == zone(coord.first, coord.second - 1) && pointBas && pointHaut)
		connecte = false;
	if(zone(coord.first + 1, coord.second) == zone(coord.first, coord.second + 1) && (pointHaut || pointGauche) && estPoint(coord.first + 1, coord.second + 1))
		connecte = false;
	if(zone(coord.first + 1, coord.second) == zone(coord.first, coord.second - 1) && (pointHaut || pointDroite) && estPoint(coord.first + 1, coord.second - 1))
		connecte = false;
	if(zone(coord.first - 1, coord.second) == zone(coord.first, coord.second + 1) && (pointBas || pointGauche) && estPoint(coord.first - 1, coord.second + 1))
		connecte = false;
	if(zone(coord.first - 1, coord.second) == zone(coord.first, coord.second - 1) && (pointBas || pointDroite) && estPoint(coord.first - 1, coord.second - 1))
		connecte = false;

	if(toucheInf && connecte) {
		setVal(getInfo(coord).id, getInfo(coord).id);
	}
	else {
		setVal(getInfo(coord).id, 0);
	}
}

void dfs(const pair<int, int> coord, int couleur) {
	if(!existInfo(coord))
		return;
	if(getInfo(coord).zone == 0 || (couleur != 0 && getInfo(coord).zone != -1))
		return;
	if(getInfo(coord).id != -1)
		return;

	getInfo(coord).zone = couleur;

	for(int iDep = 0;iDep < 8;iDep++) {
		update({coord.first + deps[iDep][0], coord.second + deps[iDep][1]});
	}

	for(int iDep = 0;iDep < 4;iDep++) {
		dfs({coord.first + deps[2 * iDep][0], coord.second + deps[2 * iDep][1]}, couleur);
	}
}

int taille(const pair<int, int> coord) {
	if(!existInfo(coord))
		return 0;
	if(getInfo(coord).id == -1)
		return 0;

	if(getInfo(coord).estPasse)
		return 0;
	getInfo(coord).estPasse = true;

	int t = 1;
	for(int iDep = 0;iDep < 8;iDep++) {
		t += taille({coord.first + deps[iDep][0], coord.second + deps[iDep][1]});
	}

	return t;
}

int main() {
	int nbPoints, type;
	scanf("%d%d", &nbPoints, &type);

	pair<int, int> mini = {1000000000, 1000000000};
	for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
		int lig, col;
		scanf("%d%d", &lig, &col);

		points.push_back({lig, col});

		getInfo({lig, col}) = Info();
		for(int iDep = 0;iDep < 8;iDep++) {
			getInfo({lig + deps[iDep][0], col + deps[iDep][1]}) = Info();
			mini = min(mini, {lig + deps[iDep][0], col + deps[iDep][1]});
		}
	}

	for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
		getInfo(points[iPoint]) = Info(iPoint);
	}

	//check connexe ?
	if(taille(points[0]) != nbPoints) {
		printf("NO\n");
		return 0;
	}

	int nbZones = 0;
	dfs(mini, nbZones++);

	//todo
	for(int i = 0;i < MOD;i++) {
		for(auto info : infos[i]) {
			if(info.second.zone == -1 && info.second.id == -1)
				dfs(info.first, nbZones++);
		}
	}

	printf("YES\n");

	vector<int> ordre;
	for(int iFois = 0;iFois < nbPoints;iFois++) {
		int melId = arbre[1];
		ordre.push_back(melId);
		setVal(melId, 0);

		getInfo(points[melId]).id = -1;
		dfs(points[melId], 0);	
	}

	while(!ordre.empty()) {
		printf("%d\n", ordre.back() + 1);
		ordre.pop_back();
	}
	return 0;
}