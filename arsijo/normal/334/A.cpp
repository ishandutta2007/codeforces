//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int n, a;
	cin >> n;
	a = n * n;
	for(int i = 0; i < n; i++){
		for (int j = 0; j < (n / 2); j++){
			cout << (i + 1 + (j * n)) << " " << (a - i - (j * n)) << " ";
		}
		cout << endl;
	}

}