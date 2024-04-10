#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	int i=1;
	while(i*i<x) i++;
	if(i*(i-1)>=x) cout << (4*i-2) << endl;
	else cout << 4*i << endl;
	return 0;
}