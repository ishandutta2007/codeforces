#include <iostream>
#include <cmath>

using namespace std;

const int INFINI = 1000 * 1000 * 1000;

int main() {
	int v;
	cin >> v;
	
	if(v == 1)
		cout << -1 << endl;
	else
		cout << v << " " << v + 1 << " " << v*(v+1) << endl;
	return 0;
}