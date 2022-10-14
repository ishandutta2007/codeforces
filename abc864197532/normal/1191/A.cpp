#include <iostream>
#include <vector> // vector
#include <algorithm> // sort
#include <math.h> // math
#include <map> // map
#include <string> // string
using namespace std;

int main () {
	int x;
	cin >> x;
	int k=x%4;
	if (k==0 or k==1) {
		cout << 1-k << " A" << endl;
	} else if (k==3) cout << 2 << " A" << endl;
	else cout << "1 B" << endl;
}