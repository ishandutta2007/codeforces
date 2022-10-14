#include <iostream>
using namespace std;

int main () {
	int n;
	cin >> n;
	for (int t=0;t<n;++t) {
		long long int k,x;
		cin >> k >> x;
		cout << x+(k-1)*9 << endl;
	}
}