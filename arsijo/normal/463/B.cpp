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

	int ans = 0;

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if (a > ans){
			ans = a;
		}
	}

	cout << ans;
}