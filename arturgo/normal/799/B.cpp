#include <iostream>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;

int prix[200 * 1000];
bool estPris[200 * 1000];

struct CompPull {
	bool operator() (const int &a, const int &b) {
		return prix[a] > prix[b];
	}
};

priority_queue<int, vector<int>, CompPull> pulls[3];

int main() {
	int nbPulls;
	cin >> nbPulls;
	
	for(int iPull = 0;iPull < nbPulls;iPull++) {
		cin >> prix[iPull];
	}
	
	for(int iPull = 0;iPull < nbPulls;iPull++) {
		int coul;
		cin >> coul;
		
		pulls[coul - 1].push(iPull);
	}
	
	for(int iPull = 0;iPull < nbPulls;iPull++) {
		int coul;
		cin >> coul;
		
		pulls[coul - 1].push(iPull);
	}
	
	int nbClients;
	cin >> nbClients;
	
	for(int iClient = 0;iClient < nbClients;iClient++) {
		int coul;
		cin >> coul;
		
		while(!pulls[coul - 1].empty() && estPris[pulls[coul - 1].top()]) {
			pulls[coul - 1].pop();
		}
		
		if(pulls[coul - 1].empty())
			cout << -1 << " ";
		else {
			cout << prix[pulls[coul - 1].top()] << " ";
			estPris[pulls[coul - 1].top()] = true;
		}
	}
	
	cout << endl;
	
	return 0;
}