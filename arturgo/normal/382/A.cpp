#include <iostream>
using namespace std;

int main() {
	int curPos = 0;
	string poids[2];
	
	string line;
	cin >> line;
	
	for(char car : line) {
		if(car == '|')
			curPos++;
		else
			poids[curPos] += car;
	}
	
	string r;
	cin >> r;
	
	for(char car : r) {
		if(poids[0].size() < poids[1].size())
			poids[0] += car;
		else
			poids[1] += car;
	}
	
	if(poids[0].size() != poids[1].size())
		cout << "Impossible" << endl;
	else
		cout << poids[0] << "|" << poids[1] << endl;
}