#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INFINI = 2000 * 1000 * 1000;

struct Event {
	int pos, jour, type;
	int mil, taille;
};

bool operator < (const Event& a, const Event& b) {
	if(a.pos != b.pos)
		return a.pos < b.pos;
	if(a.jour != b.jour)
		return a.jour < b.jour;
	return a.type < b.type;
}

int nbJours, limite;
vector<Event> events;

vector<bool> oks;

int maxCoord1 = -INFINI;
int maxCoord2 = -INFINI;

void balaye() {
	int curPos = -INFINI;
	int hauteur = 0;
	
	set<pair<int, int>> incs, decs;
	
	for(int iDeb = 0;iDeb < (int)events.size();) {
		if(hauteur > limite) {
			int p = curPos;
			int h = hauteur - limite;
			
			//cerr << "ICI" << p << " " << h << endl;
			
			maxCoord1 = max(maxCoord1, p + h);
			maxCoord2 = max(maxCoord2, h - p);
		}
	
		//cerr << curPos << " " << hauteur << endl;
		hauteur += (events[iDeb].pos - curPos) * ((int)incs.size() - (int)decs.size());
		
		int iFin = iDeb;
		while(iFin != (int)events.size() && events[iDeb].pos == events[iFin].pos) {
			Event e = events[iFin];
			
			if(e.type == 0) {
				incs.insert({e.mil - e.taille, e.jour});
			}
			else if(e.type == 1) {
				incs.erase({e.mil - e.taille, e.jour});
				decs.insert({e.mil + e.taille, e.jour});
			}
			else if(e.type == 2) {
				decs.erase({e.mil + e.taille, e.jour});
			}
			
			iFin++;
		}
		
		curPos = events[iDeb].pos;
		iDeb = iFin;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		cin >> nbJours >> limite;
		
		oks = vector<bool>(nbJours, true);
		
		events.clear();
		maxCoord1 = maxCoord2 = -INFINI;
		
		vector<pair<int, int>> jours;
		for(int iJour = 0;iJour < nbJours;iJour++) {
			int pos, taille;
			cin >> pos >> taille;
			jours.push_back({pos, taille});
			
			events.push_back({pos - taille, iJour, 0, pos, taille});
			events.push_back({pos, iJour, 1, pos, taille});
			events.push_back({pos + taille, iJour, 2, pos, taille});
		}
		
		sort(events.begin(), events.end());
		
		balaye();
		
		//cerr << maxCoord1 << " " << maxCoord2 << endl;
		
		for(pair<int, int> jour : jours) {
			int coord1 = jour.first + jour.second;
			int coord2 = jour.second - jour.first;
			
			if(coord1 >= maxCoord1 && coord2 >= maxCoord2) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		cout << endl;
	}
	return 0;
}