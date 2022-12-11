#include <iostream>
#include <vector>
using namespace std;

vector<long long> profs;

void gen(long long p) {
	if(p == (long long)profs.size()) {
		return;
	}
	
	cout << "(";
	gen(p + 1);
	cout << ")";
	
	for(long long iFois = 0;iFois < profs[p] - 1;iFois++) {
		cout << "()";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	long long n, k;
	cin >> n >> k;
	
	for(long long iFois = 0;iFois < n;iFois++) {
		if(k >= (long long)profs.size()) {
			k -= profs.size();
			profs.push_back(1);
		}
		else {
			profs[k]++;
			k = 0;
		}
	}
	
	if(k != 0) {
		cout << "Impossible" << endl;
	}
	else {
		gen(0);
		cout << endl;
	}
}