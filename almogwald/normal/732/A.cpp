#include <iostream>
#include <string>

using namespace std;
int main()
{
	//int pizza[200000],n;
	int k,r;
	cin >> k;
	cin >> r;
	for (int i = 1; i < 11; i++) {
		if ((k*i) % 10 == r || (k*i) % 10 == 0) {
			cout << i << '\n';
			break;
		}
	}
	
	//delete[] pizza;
	return 0;
}