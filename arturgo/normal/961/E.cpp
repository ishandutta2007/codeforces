#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
	int temps, position;
	Event(int _temps = 0, int _position = 0) {
		temps = _temps;
		position = _position;
	}
};

bool operator < (const Event &a, const Event &b) {
	return a.temps < b.temps;
}

int arbre[(1 << 19)];

void ajoute(int val, int pos) {
	pos += (1 << 18);
	
	while(pos != 0) {
		arbre[pos] += val;
		pos /= 2;
	}
}

int somme(int deb, int fin) {
	int s = 0;
	deb += (1 << 18);
	fin += (1 << 18);
	while(deb < fin) {
		if(deb % 2 == 1) {
			s += arbre[deb];
			deb++;
		}
		if(fin % 2 == 1) {
			fin--;
			s += arbre[fin];
		}
		deb /= 2;
		fin /= 2;
	}
	return s;
}

int nbEpisodes[(1 << 18)];
vector<Event> events;

int main() {
	int nbSaisons;
	cin >> nbSaisons;
	
	for(int iSaison = 0;iSaison < nbSaisons;iSaison++) {
		cin >> nbEpisodes[iSaison];
		
		ajoute(1, iSaison);
		events.push_back(Event(nbEpisodes[iSaison], iSaison));
	}
	
	sort(events.begin(), events.end());
	
	long long s = 0;
	int iEvent = 0;
	for(int iEpisode = 0;iEpisode < nbSaisons;iEpisode++) {
		while(iEvent < (int)events.size() && events[iEvent].temps == iEpisode) {
			ajoute(-1, events[iEvent].position);
			iEvent++;
		}
		
		s += somme(0, min((1 << 18), nbEpisodes[iEpisode]));
		if(nbEpisodes[iEpisode] > iEpisode)
			s--;
	}
	
	cout << s / 2 << endl;
	return 0;
}