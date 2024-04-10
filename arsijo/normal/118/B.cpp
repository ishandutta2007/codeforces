//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

void print(int t, int n){
	int g = ((n - t) * 2);
	for (int j = 0; j < g; j++){
		cout << " ";
	}
	for (int j = 0; j < t; j++){
		cout << j << " ";
	}
	cout << t;
	for (int j = t-1; j >= 0; j--){
		cout << " " << j;
	}
	/*for (int j = 0; j < g; j++){
			cout << " ";
	}*/
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <=n; i++){
		print(i, n);
	}
	for (int i = n - 1; i >= 0; i--){
		print(i, n);
	}
	return 0;
}