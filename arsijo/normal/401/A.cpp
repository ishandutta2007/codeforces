//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, x;
	cin >> n >> x;

	long long sum = 0;

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		sum += a;
	}

	sum = abs(sum);

	int ans = sum / x;

	if(sum % x != 0){
		ans++;
	}

	cout << ans;

}