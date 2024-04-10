#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <iomanip>
using namespace std;

map<pair<int, int>, int> ordre;

vector<int> suivs[100];

double esperances[2][100];

int main() {
	ios_base::sync_with_stdio(false);

	int cur = 0;
	for(int i = 9;i >= 0;i--) {
		if(i % 2 == 1) {
			for(int j = 0;j < 10;j++) {
				ordre[{i, j}] = cur++;
			}
		}
		else if(i % 2 == 0) {
			for(int j = 9;j >= 0;j--) {
				ordre[{i, j}] = cur++;
			}
		}
	}

	for(int i = 0;i < 10;i++) {
		for(int j = 0;j < 10;j++) {
			int taille;
			cin >> taille;
			if(taille != 0) {
				suivs[ordre[{i, j}]].push_back(ordre[{i - taille, j}]);
			}
		}
	}

	esperances[0][99] = 0;
	esperances[1][99] = 0;

	for(int i = 98;i >= 0;i--) {
		double esp = 1;

		int nbMiss = 0;
		for(int d = 1;d <= 6;d++) {
			if(d + i <= 99)
				esp += esperances[1][i + d] / 6;
			else
				nbMiss++;
		}

		esp = 6 * esp / (6 - nbMiss);
		esperances[0][i] = esp;

		for(int s : suivs[i]) {
			esp = min(esp, esperances[0][s]);
		}

		esperances[1][i] = esp;
	}

	cout << setprecision(18) << fixed << min(esperances[0][0], esperances[1][0]) << endl;
	return 0;
}