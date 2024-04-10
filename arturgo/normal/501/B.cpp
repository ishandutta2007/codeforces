#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

map<string, string> chs;

int main() {	
	int nbChanges;
	cin >> nbChanges;
	
	for(int iChange = 0;iChange < nbChanges;iChange++) {
		string debut, fin;
		cin >> debut >> fin;
		
		string init = debut;
		if(chs.find(debut) != chs.end()) {
			init = chs[debut];
			chs.erase(debut);
		}
		
		chs[fin] = init;
	}
	
	cout << chs.size() << endl;
	
	for(pair<string, string> ch : chs) {
		cout << ch.second << " " << ch.first << endl;
	}
	return 0;
}