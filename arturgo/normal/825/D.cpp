#include <iostream>
#include <vector>
using namespace std;

int occS[26];
int occT[26];

int nbChoix;
vector<char> choix;

int maximise() {
	for(int iFois = 0;iFois <= 1000 * 1000;iFois++) {
		for(int iLettre = 0;iLettre < 26;iLettre++) {
			int nbAjoute = max(0, iFois * occT[iLettre] - occS[iLettre]);
			for(int i = 0;i < nbAjoute;i++) {
				if(nbChoix == 0)
					return iFois - 1;
				occS[iLettre]++;
				choix.push_back(iLettre + 'a');
				nbChoix--;
			}
		}
	}
}

int main() {
	string s, t;
	cin >> s >> t;
	
	for(char car : s) {
		if(car == '?')
			nbChoix++;
		else
			occS[car - 'a']++;
	}
	
	for(char car : t) {
		occT[car - 'a']++;
	}
	
	maximise();
	
	for(char car : s) {
		if(car == '?') {
			cout << choix.back();
			choix.pop_back();
		}
		else {
			cout << car;
		}
	}
	cout << endl;
}