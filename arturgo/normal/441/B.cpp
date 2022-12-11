#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int vals[5000];
list<int> ids[5000];

int main() {
	int nb, maxi;
	cin >> nb >> maxi;
	
	for(int i = 0;i < nb;i++) {
		int date;
		cin >> date >> vals[i];
		ids[date].push_back(i);
		ids[date + 1].push_front(i);
	}
	
	int tot = 0;
	for(int t = 0;t < 5000;t++) {
		int reste = maxi;
		for(int id : ids[t]) {
			int e = min(reste, vals[id]);
			reste -= e;
			vals[id] -= e;
			tot += e;
		}
	}	
	
	cout << tot << endl;
}