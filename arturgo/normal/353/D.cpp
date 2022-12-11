#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string chaine;
	cin >> chaine;
	
	reverse(chaine.begin(), chaine.end());
	while(!chaine.empty() && chaine.back() == 'F') {
		chaine.pop_back();
	}
	reverse(chaine.begin(), chaine.end());
	
	int nbFillesAvant = 0;
	
	int derTi = 0;
	for(int pos = 0;pos < (int)chaine.size();pos++) {
		if(chaine[pos] == 'F') {
			derTi = max(derTi + 1, pos - nbFillesAvant);
			nbFillesAvant++;
		}
	}
	
	cout << derTi << endl;
	return 0;
}