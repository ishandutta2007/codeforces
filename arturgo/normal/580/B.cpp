#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > amis;

int main() {
	int nbAmis, maxDiff;
	cin >> nbAmis >> maxDiff;
	
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		int argent, amitie;
		cin >> argent >> amitie;
		
		amis.push_back({argent, amitie});
	}
	
	sort(amis.begin(), amis.end());
	
	int iFin = 0;
	long long somme = 0;
	long long mel = 0;
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		while(iFin != nbAmis && amis[iAmi].first + maxDiff > amis[iFin].first) {
			somme += amis[iFin].second;
			iFin++;
		}
		mel = max(mel, somme);
		somme -= amis[iAmi].second;
	}
	
	cout << mel << endl;
}