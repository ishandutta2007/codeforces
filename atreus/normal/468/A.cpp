#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n < 4){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (n % 2 == 1){
		for (int i = 7; i <= n; i += 2)
			cout << i << " - " << i - 1 << " = " << 1 << endl;
		cout << "5 * 4 = 20" << endl << "20 + 3 = 23" << endl << "23 + 2 = 25" << endl << "25 - 1 = 24" << endl;
		for (int i = 7; i <= n; i+= 2)
			cout << "24 * 1 = 24" << endl;
	}
	if (n % 2 == 0){
		cout << "1 * 2 = 2" << endl << "2 * 3 = 6" << endl << "6 * 4 = 24" << endl;
		for (int i = 6; i <= n; i += 2){
			cout << i << " - " << i - 1 << " = " << 1 << endl;
			cout << "24 * 1 = 24" << endl;
		}
	}
}