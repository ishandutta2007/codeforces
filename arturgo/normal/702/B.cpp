#include <iostream>
#include <cmath>
#include <map>
using namespace std;

long long puis2[32];

int main() {
	int nb;
	cin >> nb;
	
	puis2[0] = 1;
	for(int p = 1;p <= 31;p++) {
		puis2[p] = 2 * puis2[p-1];
	}
	
	long long nbP = 0;
	map<long long, int> s;
	for(int i = 0;i < nb;i++) {
		long long v;
		cin >> v;
		
		for(int p = 0;p <= 31;p++) {
			if(s.find(puis2[p] - v) != s.end()) {
				nbP += s[puis2[p] - v];
			}
		}
		
		if(s.find(v) == s.end()) {
			s[v] = 0;
		}
		s[v]++;
	}
	
	cout << nbP << endl;
	return 0;
}