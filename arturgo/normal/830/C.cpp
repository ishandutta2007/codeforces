#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
	int mod, val;
	int bamboo;
	
	Event(int _mod = 0, int _bamboo = 0, int _val = 0) {
		mod = _mod;
		bamboo = _bamboo;
		val = _val;
	}
};

bool operator < (const Event &a, const Event &b) {
	if(a.mod == b.mod) {
		return a.val > b.val;
	}
	return a.mod < b.mod;
}

vector<Event> events;

int nbBamboos;
long long maxCoupe;
long long hauteurs[200];
long long curTerme[200];

void genEvents(int bamboo) {
	for(long long div = 1;div * div <= 2 * hauteurs[bamboo];div++) {
		long long val = (hauteurs[bamboo] + div - 1) / div;
		events.push_back(Event(div, bamboo, val));
	}
	
	for(long long val = 1;val * val <= 2 * hauteurs[bamboo];val++) {
		long long pos = (hauteurs[bamboo] + val - 1) / val;
		events.push_back(Event(pos, bamboo, val));
	}
}

int main() {
	cin >> nbBamboos >> maxCoupe;
	
	long long curSomme = 0;
	long long borneSup = maxCoupe;
	
	for(int iBamboo = 0;iBamboo < nbBamboos;iBamboo++) {
		cin >> hauteurs[iBamboo];
		borneSup += hauteurs[iBamboo];
		genEvents(iBamboo);
	}
	
	sort(events.begin(), events.end());
	
	long long maxPos = 0;
	
	for(int iDebut = 0;iDebut < (int)events.size();) {
		int iFin = iDebut;
		
		while(iFin != (int)events.size() && events[iFin].mod == events[iDebut].mod) {
			curSomme -= curTerme[events[iFin].bamboo];
			curTerme[events[iFin].bamboo] = events[iFin].val;
			curSomme += curTerme[events[iFin].bamboo];
			iFin++;
		}
		
		int derPos = maxPos;
		
		if(iFin != (int)events.size())
			maxPos = max(
				maxPos,
				min((long long)events[iFin].mod - 1, 
					borneSup / curSomme
				)
			);
		else
			maxPos = max(
				maxPos,
				borneSup / curSomme
			);
		
		if(maxPos < events[iDebut].mod)
			maxPos = derPos;
		
		iDebut = iFin;
	}
	
	cout << maxPos << endl;
	return 0;
}