#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int mx = 25;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		if(mx < x) mx = x;
		
	}
	cout << mx - 25 << endl;
	return 0;
}