#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	int pizza[200000],n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pizza[i];
	}
	for (int i = 0; i < n-1; i++) {
		if (pizza[i] % 2 == 0) {
			continue;
		}
		else {
			if (pizza[i + 1] == 0) {
				cout << "NO\n";
				return 0;
			}
			pizza[i + 1]--;
		}
	}
	if(pizza[n-1]%2==1){
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	return 0;
}