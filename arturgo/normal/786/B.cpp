#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long distances[(1 << 19)];
bool estPasse[(1 << 19)];
vector<pair<int, int>> voisins[(1 << 19)];

void ajouteMontants(int noeud) {
	if(noeud >= (1 << 19))
		return;
	if(noeud > 3) {
		voisins[noeud].push_back({0, noeud / 2});
	}
	ajouteMontants(2 * noeud);
	ajouteMontants(2 * noeud + 1);
}

void ajouteDescendants(int noeud) {
	if(noeud >= (1 << 19))
		return;
	if(noeud > 3) {
		voisins[noeud / 2].push_back({0, noeud});
	}
	ajouteDescendants(2 * noeud);
	ajouteDescendants(2 * noeud + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbPlanetes, nbArcs, terre;
	cin >> nbPlanetes >> nbArcs >> terre;
	
	for(int i = 0;i < (1 << 17);i++) {
		voisins[i + 3*(1 << 17)].push_back({0, i + (1 << 18)});
	}
	
	for(int iArc = 0;iArc < nbArcs;iArc++) {
		int type;
		cin >> type;
		
		if(type == 1) {
			int deb, fin, cost;
			cin >> deb >> fin >> cost;
			
			voisins[deb - 1 + (1 << 18)].push_back({cost, fin - 1 + 3 * (1 << 17)});
		}
		else if(type == 2) {
			int deb, l, r, cost;
			cin >> deb >> l >> r >> cost;
			
			l += (1 << 18) + (1 << 17) - 1;
			r += (1 << 18) + (1 << 17);
			while(l < r) {
				if(l % 2 == 1) {
					voisins[deb - 1 + (1 << 18)].push_back({cost, l});
					l++;
				}
				if(r % 2 == 1) {
					r--;
					voisins[deb - 1 + (1 << 18)].push_back({cost, r});
				}
				l /= 2;
				r /= 2;
			}
		}
		else {
			int fin, l, r, cost;
			cin >> fin >> l >> r >> cost;
			
			l += (1 << 18) - 1;
			r += (1 << 18);
			
			while(l < r) {
				if(l % 2 == 1) {
					voisins[l].push_back({cost, fin - 1 + 3*(1 << 17)});
					l++;
				}
				if(r % 2 == 1) {
					r--;
					voisins[r].push_back({cost, fin - 1 + 3*(1 << 17)});
				} 
				l /= 2;
				r /= 2;
			}
		}
	}
	
	ajouteDescendants(3);
	ajouteMontants(2);
	
	priority_queue<pair<long long, int>> events;
	events.push({0, (terre - 1) + (1 << 18)});
	
	while(!events.empty()) {
		pair<long long, int> cur = events.top();
		events.pop();
		
		if(estPasse[cur.second])
			continue;
		estPasse[cur.second] = true;
		distances[cur.second] = -cur.first;
		
		for(pair<int, int> voisin : voisins[cur.second]) {
			events.push({cur.first - voisin.first, voisin.second});
		}
	}
	
	for(int iPlanete = 0;iPlanete < nbPlanetes;iPlanete++) {
		if(!estPasse[iPlanete + (1 << 18)])
			cout << -1 << " ";
		else
			cout << distances[iPlanete + (1 << 18)] << " ";
	}
	cout << endl;
	return 0;
}