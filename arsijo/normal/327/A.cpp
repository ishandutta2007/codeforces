//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	int ar[n];

	int max = 0;

	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}

	for(int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			int k = 0;
			int g[n];
			copy(ar, ar + n, g);
			for (int z = i; z <= j; z++){
				g[z] = 1 - g[z];
			}
			for (int z = 0; z < n; z++){
				k += g[z];
			}
			if (k > max){
				max = k;
			}
		}
	}
	cout << max;

}