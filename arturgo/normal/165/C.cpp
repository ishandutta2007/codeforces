#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int k;
string chaine;

int cumul[1000 * 1000 + 1];

int main() {
	int k;
	cin >> k;
	
	cin >> chaine;
	
	for(int i = 0;i < (int)chaine.size();i++) {
		cumul[i + 1] = cumul[i] + (chaine[i] == '1');
	}
	
	long long tot = 0;
	for(int i = 0;i < (int)chaine.size();i++) {
		auto paire = equal_range(cumul + i + 1, cumul + (int)chaine.size() + 1, cumul[i] + k);
		tot += paire.second - paire.first;
	}
	
	cout << tot << endl;
}