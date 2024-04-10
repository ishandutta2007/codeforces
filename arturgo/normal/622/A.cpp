#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long pos;
	cin >> pos;
	
	long long sum = 0;
	for(long long iV = 1;sum + iV < pos;iV++)
		sum += iV;
	
	cout << pos - sum << endl;
	return 0;
}