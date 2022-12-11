#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long sommeCut = 0;
	for(int iA = 0;iA < n;iA++) {
		long long cur = 0;
		cin >> cur;
		sommeCut += cur - 1;
		if(sommeCut % 2 == 1) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
	return 0;
}