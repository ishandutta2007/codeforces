#include <iostream>
#include <algorithm>
using namespace std;

struct Event {
	int pos, chaine;
	Event(int _pos = 0, int _chaine = 0) {
		pos = _pos;
		chaine = _chaine;
	}
};

bool operator < (const Event &a, const Event &b) {
	return a.pos < b.pos;
}

string chaines[200 * 1000];
vector< Event > events; 

int main() {
	ios_base::sync_with_stdio(false);
	int nbChaines;
	cin >> nbChaines;
	
	int maxi = 0;
	for(int iChaine = 0;iChaine < nbChaines;iChaine++) {
		int nbFois;
		cin >> chaines[iChaine] >> nbFois;
		
		for(int iFois = 0;iFois < nbFois;iFois++) {
			int pos;
			cin >> pos;
			
			maxi = max(maxi, pos - 1 + (int)chaines[iChaine].size());
			events.push_back(Event(pos - 1, iChaine));
		}
	}
	
	sort(events.begin(), events.end());
	
	int debut = 0;
	
	int finEvent = 0;
	int pos = 0, chaine = 0;
	for(int iPos = 0;iPos < maxi;iPos++) {
		while(debut != (int)events.size() && iPos == events[debut].pos) {
			if(events[debut].pos + (int)chaines[events[debut].chaine].size() > finEvent) {
				finEvent = events[debut].pos + chaines[events[debut].chaine].size();
				pos = 0;
				chaine = events[debut].chaine;
			}
			
			debut++;
		}
		
		if(finEvent <= iPos) {
			cout << "a";
		}
		else {
			cout << chaines[chaine][pos];
			pos++;
		}
	}
	
	cout << endl;
}