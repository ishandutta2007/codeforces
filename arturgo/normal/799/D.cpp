#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

bool estPasse[35][200 * 1000];

vector<int> mults;

int main() {
	int hf, lf, hd, ld, nbMults;
	cin >> hf >> lf >> hd >> ld >> nbMults;
	
	for(int iMult = 0;iMult < nbMults;iMult++) {
		int val;
		cin >> val;
		mults.push_back(val);
	}
	
	sort(mults.begin(), mults.end(), greater<int>());
	while(mults.size() > 34) mults.pop_back();
	
	estPasse[0][1] = true;
	
	long long prod = 1;
	int mini = 100;
	
	for(int iCoup = 0;iCoup < (int)mults.size();iCoup++) {
		for(int iPos = 1;iPos < 200 * 1000;iPos++) {
			if(estPasse[iCoup][iPos]) {
				long long curProd = iPos * (long long)hd;
				long long autProd = prod / iPos * ld;
				
				if((curProd >= hf && autProd >= lf) || (curProd >= lf && autProd >= hf)) {
					cout << min(mini, iCoup) << endl;
					return 0;
				}
			
				estPasse[iCoup + 1][iPos] = true;
				
				if(iPos * mults[iCoup] >= 200 * 1000) {
					long long autProd = prod / iPos * max(ld, hd);
					for(int iCoup2 = iCoup + 1;iCoup2 < (int)mults.size();iCoup2++) {
						autProd *= mults[iCoup2];
						if(autProd >= min(hf, lf)) {
							mini = min(mini, iCoup2 + 1);
							break;
						}
					}
				}
				else {
					estPasse[iCoup + 1][iPos * mults[iCoup]] = true;
				}
			}
		}
		
		prod *= mults[iCoup];
	}
	
	int iCoup = (int)mults.size();
	for(int iPos = 1;iPos < 200 * 1000;iPos++) {
		if(estPasse[iCoup][iPos]) {
			long long curProd = iPos * (long long)hd;
			long long autProd = prod / iPos * ld;
			
			if((curProd >= hf && autProd >= lf) || (curProd >= lf && autProd >= hf)) {
				cout << min(mini, iCoup) << endl;
				return 0;
			}
		}
	}
	
	if(mini == 100)
		cout << -1 << endl;
	else {
		cout << mini << endl;
	}
	
	return 0;
}