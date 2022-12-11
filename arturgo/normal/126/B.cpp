#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

vector<int> kmp(string chaine) {
	vector<int> sol;
	sol.push_back(-1);
	
	for(int iCar = 0;iCar < (int)chaine.size();iCar++) {
		int cur = sol.back();
		while(cur != -1 && chaine[cur] != chaine[iCar]) {
			cur = sol[cur];
		}
		sol.push_back(cur + 1);
	}
	
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	string chaine;
	cin >> chaine;
	
	vector<int> bords = kmp(chaine);
	
	int cur = bords.back();
	if(cur == 0) {
		cout << "Just a legend" << endl;
		return 0;
	}
	
	for(int iPos = 0;iPos < (int)chaine.size();iPos++) {
		if(bords[iPos] == cur) {
			cout << chaine.substr(0, cur) << endl;
			return 0;
		}
	}
	
	if(bords[cur] == 0) {
		cout << "Just a legend" << endl;
		return 0;
	}
	
	cout << chaine.substr(0, bords[cur]) << endl;
	return 0;
}