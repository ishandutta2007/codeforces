#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

long long fin;

vector<long long> solution;

bool afficheChemin(long long deb) {
	if(deb > fin)
		return false;
	if(deb == fin) {
		solution.push_back(deb);
		return true;
	}
	
	if(afficheChemin(deb * 10 + 1) ||
	afficheChemin(deb * 2)) {
		solution.push_back(deb);
		return true;
	}
	return false;
}

int main() {
	long long deb;
	cin >> deb >> fin;
	
	afficheChemin(deb);
	
	if(solution.empty())
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << solution.size() << endl;
		while(!solution.empty()) {
			cout << solution.back() << " ";
			solution.pop_back();
		}
		cout << endl;
	}
	return 0;
}