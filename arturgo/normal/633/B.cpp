#include <iostream>
#include <algorithm>
using namespace std;

int v5fact(int n) {
	long long p = 5;
	
	int v = 0;
	for(int k = 1;k <= 10;k++) {
		v += n / p;
		p *= 5;
	}
	
	return v;
}

int main() {
	int m;
	cin >> m;
	
	vector<int> r;
	for(int n = 0;n <= 500 * 1000;n++) {
		if(v5fact(n) == m)
			r.push_back(n);
	}
	
	cout << r.size() << endl;
	
	for(int e : r) {
		cout << e << " ";
	}
	cout << endl;
}