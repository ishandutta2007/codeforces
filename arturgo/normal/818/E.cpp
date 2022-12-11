#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > factors(int v) {
	vector<pair<int, int> > res;
	int div = 2;
	while(div * div <= v) {
		int nb = 0;
		while(v % div == 0) {
			v /= div;
			nb++;
		}
		if(nb != 0)
			res.push_back({div, nb});
		div++;
	}
	
	if(v != 1) {
		res.push_back({v, 1});
	}
	
	return res;
}

vector< pair<int, int> > fact;
int cumuls[40][100 * 1000];

bool estValide(int deb, int fin) {
	for(int iCumul = 0;iCumul < fact.size();iCumul++) {
		int curVal = cumuls[iCumul][fin + 1] - cumuls[iCumul][deb];
		if(curVal < fact[iCumul].second)
			return false;
	}
	return true;
}

int main() {
	int n, k;
	cin >> n >> k;
	
	fact = factors(k);
	
	long long nbPossibles = 0;
	
	int deb = -1;
	for(int i = 0;i < n;i++) {
		int val;
		cin >> val;
		
		for(int iCumul = 0;iCumul < fact.size();iCumul++) {
			int puis = 0;
			while(val % fact[iCumul].first == 0) {
				puis++;
				val /= fact[iCumul].first;
			}
			
			cumuls[iCumul][i + 1] = cumuls[iCumul][i] + puis; 
		}
		
		while(deb < i && estValide(deb + 1, i)) {
			deb++;
		}
		
		nbPossibles += deb + 1;
	}
	
	cout << nbPossibles << endl;
}