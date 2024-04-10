#include <iostream>
#include <vector>
using namespace std;

const int INFINI = 1000 * 1000 * 1000;
string phrase, mot;

vector<int> kmp(string mot) {
	vector<int> sol;
	sol.push_back(-1);
	
	for(int iPos = 0;iPos < (int)mot.size();iPos++) {
		int cur = sol.back();
		
		while(cur != -1 && mot[cur] != mot[iPos]) {
			cur = sol[cur];
		}
		
		sol.push_back(cur + 1);
	}
	
	return sol;
}

int dyn[2][200 * 1000];

int main() {
	cin >> phrase >> mot;
	
	vector<int> bords = kmp(mot);
	
	for(int iPos2 = 0;iPos2 < (int)mot.size();iPos2++) {
		dyn[0][iPos2] = -INFINI;
	}
	dyn[0][0] = 0;
	
	for(int iPos1 = 0;iPos1 < (int)phrase.size();iPos1++) {
		int cur = iPos1 & 1;
		int aut = 1 - cur;
		
		dyn[aut][0] = dyn[cur][0];
		for(int iPos2 = 0;iPos2 < (int)mot.size();iPos2++) {
			if(phrase[iPos1] == mot[iPos2] || phrase[iPos1] == '?')
				dyn[aut][iPos2 + 1] = dyn[cur][iPos2];
			else
				dyn[aut][iPos2 + 1] = -INFINI;
		}
		
		dyn[aut][bords.back()] = max(dyn[aut][bords.back()], dyn[aut][(int)mot.size()] + 1);
		
		for(int iPos2 = (int)mot.size() - 1;iPos2 >= 1;iPos2--) {
			dyn[aut][bords[iPos2]] = max(dyn[aut][bords[iPos2]], dyn[aut][iPos2]);
		}
	}
	
	cout << dyn[phrase.size() & 1][0] << endl;
	return 0;
}