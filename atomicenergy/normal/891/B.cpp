#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;
//mod p^n, how many ps;


int main() {
	int n;
	cin >> n;

	map<int, int> mi;
	map<int, int> in;
	vector<pair<int, int> > numind;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		numind.push_back(make_pair(x, i));

		in[i] = x;
	}
	sort(numind.begin(), numind.end());
	for(int i=0; i<n; i++){
		mi[numind[i].first] = i;
	}
	for(int i=0; i<n; i++){
		int sortedIndex = mi[in[i]];
		int newnumber = numind[((sortedIndex + 1)%n)].first;
		cout << newnumber << " ";
	}
	cout << endl;
}