#include <iostream>
#include <string>

using namespace std;
int main()
{
	bool allZ=true;
	int n, firstnotZ, some = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a != 0 && allZ) {
			allZ = false;
			firstnotZ = i;
		}
		some += a;
	}
	if (allZ) {
		cout << "NO\n";
	}
	else if(some == 0) {
		cout << "YES\n2\n";
		cout << "1 "<< firstnotZ <<"\n";
		cout << firstnotZ + 1 << " " << n <<"\n";
	}
	else {
		cout << "YES\n1\n";
		cout << "1 " << n << "\n";
	}
	//delete[] pizza;
	return 0;
}