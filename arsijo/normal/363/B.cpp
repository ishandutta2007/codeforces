//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++){
		cin >> ar[i];
	}
	long sum = 0;
	for (int i = 0; i < k; i++){
		sum += ar[i];
	}
	long min = sum;
	int minIndex = k-1;
	for(int i = k; i < n; i++){
		sum += ar[i];
		sum -= ar[i-k];
		if (sum < min){
			min = sum;
			minIndex = i;
		}
	}

	cout << minIndex - k + 2;
}