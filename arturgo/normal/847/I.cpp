#include <iostream>
#include <deque>
using namespace std;

struct Event {
	int l, c, d;
	Event(int _l = 0, int _c = 0, int _d = 0) {
		l = _l;
		c = _c;
		d = _d;
	}
};

string terrain[300];

int dirs[4][2] = {
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1}
};

int curPasse = 0;
int derPasse[300][300];
long long sons[300][300];

int nbLigs, nbCols, fact, limite;

bool estValide(int lig, int col) {
	if(lig < 0 || lig >= nbLigs || col < 0 || col >= nbCols)
		return false;
	return true;
}

deque<Event> events;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbLigs >> nbCols >> fact >> limite;
	
	for(int iLig = 0;iLig < nbLigs;iLig++) {
		cin >> terrain[iLig];
	}
	
	for(int iLig = 0;iLig < nbLigs;iLig++) {
		for(int iCol = 0;iCol < nbCols;iCol++) {
			if(terrain[iLig][iCol] == '.' || terrain[iLig][iCol] == '*')
				continue;
			int f = (terrain[iLig][iCol] - 'A' + 1);
			
			curPasse++;
			
			events.push_back(Event(iLig, iCol, 0));
			
			while(!events.empty()) {
				Event cur = events.front();
				events.pop_front();
				
				if((1 << cur.d) > f * fact)
					break;
				
				if(!estValide(cur.l, cur.c))
					continue;
				
				if(terrain[cur.l][cur.c] == '*')
					continue;
				
				if(derPasse[cur.l][cur.c] == curPasse)
					continue;
				derPasse[cur.l][cur.c] = curPasse;
				
				sons[cur.l][cur.c] += (fact * f) / (1 << cur.d);
				
				for(int i = 0;i < 4;i++) {
					int pl = cur.l + dirs[i][0], pc = cur.c + dirs[i][1];
					if(estValide(pl, pc) && derPasse[pl][pc] != curPasse) {
						events.push_back(Event(pl, pc, cur.d + 1));
					}
				}
			}
			events.clear();
		}
	}
	
	int nbConcernes = 0;
	
	for(int iLig = 0;iLig < nbLigs;iLig++) {
		for(int iCol = 0;iCol < nbCols;iCol++) {
			if(sons[iLig][iCol] > limite) {
				nbConcernes++;
			}
		}
	}
	
	cout << nbConcernes << endl;
	return 0;
}