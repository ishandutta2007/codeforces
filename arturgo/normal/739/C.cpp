#include <iostream>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;

struct Bosse {
	int deb, fin;
	Bosse(int _deb = 0, int _fin = 0) {
		deb = _deb;
		fin = _fin;
	}
};

bool operator < (const Bosse &a, const Bosse &b) {
	return a.fin - a.deb < b.fin - b.deb;
}

int nbTours, nbReqs;
long long diffs[1000 * 1000];

map<int, int> inters;
priority_queue<Bosse> bosses;

int sig(long long val) {
	if(val < 0)
		return -1;
	if(val > 0)
		return 1;
	return 0;
}

void creeBosse2(map<int, int>::iterator it) {
	auto fin = it; 
	if(fin != inters.end())
		fin++;
	if(fin != inters.end())
		fin++;
	
	if(fin != inters.end()) {
		bosses.push(Bosse(it->first, fin->first));
	}
}

void creeBosse1(map<int, int>::iterator it) {
	auto fin = it; 
	if(fin != inters.end())
		fin++;
	if(fin != inters.end())
		bosses.push(Bosse(it->first, fin->first));
}

void majInters(int pos) {
	auto cur = inters.lower_bound(pos);
	
	int curSig;
	if(cur == inters.end()) {
		curSig = 0;
	}
	else {
		curSig = cur->second;
	}
	
	inters[pos] = curSig;
	inters[pos + 1] = sig(diffs[pos]);
	
	if(curSig == sig(diffs[pos])) {
		inters.erase(pos);
	}
	
	auto suiv = inters.upper_bound(pos + 1);
	if(suiv != inters.end()
	&& suiv->second == inters[pos + 1]) {
		inters.erase(pos + 1);
	}
	
	cur = inters.lower_bound(pos);
	
	for(int iFois = 0;iFois < 2;iFois++) {
		if(cur != inters.begin())
			cur--;
	}
	
	for(int iFois = 0;iFois < 4;iFois++) {
		creeBosse2(cur);
		creeBosse1(cur);
		
		if(cur != inters.end())
			cur++;
	}
}

int main() {
	scanf("%d", &nbTours);
	
	int derHauteur;
	scanf("%d", &derHauteur);
	
	for(int iTour = 1;iTour < nbTours;iTour++) {
		int hauteur;
		scanf("%d", &hauteur);
		
		diffs[iTour - 1] = hauteur - derHauteur;
		
		derHauteur = hauteur;
	}
	
	inters[0] = 0;
	inters[nbTours - 1] = 0;
	
	for(int iTour = 0;iTour < nbTours - 1;iTour++) {
		//cout << "begin" << endl << endl << endl;
		majInters(iTour);
		//cout << "end" << endl << endl << endl;
	}
	
	scanf("%d", &nbReqs);
	
	for(int iReq = 0;iReq < nbReqs;iReq++) {
		int deb, fin, ajout;
		scanf("%d%d%d", &deb, &fin, &ajout);
		deb--;
		
		if(deb != 0) {
			diffs[deb - 1] += ajout;
			majInters(deb - 1);
		}
		
		if(fin != nbTours) {
			diffs[fin - 1] -= ajout;
			majInters(fin - 1);
		}
		
		while(!bosses.empty()) {
			Bosse cur = bosses.top();
			
			auto debIt = inters.find(cur.deb);
			auto milIt = debIt; milIt++;
			auto finIt = milIt; finIt++;
			
			if(
				debIt != inters.end()
			&&	milIt != inters.end()
			&&  milIt->second != 0
			&&  milIt->first == cur.fin
			)
				break;
			
			if(
				debIt != inters.end()
			&&	milIt != inters.end()
			&&  finIt != inters.end()
			&&  milIt->second == 1
			&&  finIt->second == -1
			&&  finIt->first == cur.fin
			)
				break;
			
			bosses.pop();
		}

		if(bosses.empty())
			printf("1\n");
		else {
			printf("%d\n", bosses.top().fin - bosses.top().deb + 1);
			//cout << bosses.top().deb << " " << bosses.top().fin << endl;
		}
		
		/*cout << "Inters---" << endl;
		
		for(pair<int, int> inter : inters) {
			cout << inter.first << " " << inter.second << endl;
		}
		
		for(int iTour = 0;iTour < nbTours - 1;iTour++) {
			cout << diffs[iTour] << " ";
		}
		cout << endl;
		cout << endl;*/
	}
}