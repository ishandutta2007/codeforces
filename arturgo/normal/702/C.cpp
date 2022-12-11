#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> xvilles, xspots;

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int iVille = 0;iVille < n;iVille++) {
		long long x;
		cin >> x;
		xvilles.push_back(x);
	}
	
	for(int iSpot = 0;iSpot < m;iSpot++) {
		long long x;
		cin >> x;
		xspots.push_back(x);
	}
	
	sort(xspots.begin(), xspots.end());
	
	long long r = 0;
	for(int iVille = 0;iVille < n;iVille++) {
		auto pos = lower_bound(xspots.begin(), xspots.end(), xvilles[iVille]);
		if(pos == xspots.begin()) {
			r = max(r, *pos - xvilles[iVille]);
		}
		else if(pos == xspots.end()) {
			pos--;
			r = max(r, xvilles[iVille] - *pos);
		}
		else {
			long long d1 = *pos - xvilles[iVille];
			pos--;
			long long d2 = xvilles[iVille] - *pos;
			r = max(r, min(d1, d2));
		}
	}
	
	cout << r << endl;
	return 0;
}