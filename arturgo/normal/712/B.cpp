#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string ch;
	cin >> ch;
	int nbL = 0,
		nbR = 0,
		nbU = 0,
		nbD = 0;
	for(char c : ch) {
		if(c == 'L')
			nbL++;
		else if(c == 'R')
			nbR++;
		else if(c == 'U')
			nbU++;
		else if(c == 'D')
			nbD++;
	}
	
	if(ch.size()%2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	
	int nbChanges = 0;
	while(abs(nbL - nbR) > 1 || abs(nbU - nbD) > 1) {
		if(nbL + 1 <= nbR - 1) {
			nbL++;
			nbR--;
		}
		else if(nbR + 1 <= nbL - 1) {
			nbR++;
			nbL--;
		}
		else if(nbU + 1 <= nbD - 1) {
			nbU++;
			nbD--;
		}
		else if(nbD + 1 <= nbU - 1) {
			nbD++;
			nbU--;
		}
		nbChanges++;
	}
	
	nbChanges += abs(nbR - nbL);
	cout << nbChanges << endl;
	return 0;
}