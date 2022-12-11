#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	
	multiset<char> as, bs;
	
	for(char car : a) as.insert(car);
	for(char car : b) bs.insert(car);
	
	int nbF = a.size() - a.size() / 2;
	while(as.size() > nbF)
		as.erase(as.lower_bound(*as.rbegin()));
	
	nbF = a.size() / 2;
	while(bs.size() > nbF)
		bs.erase(bs.begin());
	
	vector<char> fin;
	for(int iFois = 0;iFois < (int)a.size();iFois++) {
		if(iFois % 2 == 0) {
			if(iFois >= a.size() - 1 || *as.begin() < *bs.rbegin() ) {
				cout << *as.begin();
				as.erase(as.begin());
			}
			else {
				fin.push_back(*as.rbegin());
				as.erase(as.lower_bound(*as.rbegin()));
			}
		}
		else {
			if(iFois >= a.size() - 1 || *as.begin() < *bs.rbegin() ) {
				cout << *bs.rbegin();
				bs.erase(bs.lower_bound(*bs.rbegin()));
			}
			else {
				fin.push_back(*bs.begin());
				bs.erase(bs.begin());
			}
		}
	}
	
	while(!fin.empty()) {
		cout << fin.back();
		fin.pop_back();
	}
	cout << endl;
}