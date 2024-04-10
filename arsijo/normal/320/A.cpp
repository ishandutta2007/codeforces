//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	long long n;
	cin >> n;
	int count = 0;

	while (n != 0){
		if(n < 10 && n % 10 == 4){
			cout << "NO";
			return 0;
		}
		if(n % 10 == 4){
			count++;
			if (count == 3){
				cout << "NO";
				return 0;
			}
		}else{
			count = 0;
			if (n % 10 != 1){
				cout << "NO";
				return 0;
			}
		}
		n /= 10;
	}
	cout << "YES";

}