//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int s, n, g;
	cin >> s >> n;
	int a[n];
	int y[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> y[i];
	}
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[i]){
				g = a[j];
				a[j] = a[i];
				a[i] = g;
				g = y[j];
				y[j] = y[i];
				y[i] = g;
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i] >= s){
			cout << "NO";
			return 0;
		}
		s += y[i];
	}
	cout << "YES";
	return 0;
}