#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int x;
	cin >> x;
	n=n%6;
	for(int i=0; i<n; i++){
		if((n-i)%2==1) x = (4-x)%3;
		else x = (3-x)%3;
	}
	cout << x << endl;
	return 0;
}