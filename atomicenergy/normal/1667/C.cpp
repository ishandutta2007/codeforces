#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	int n;
	cin >> n;
	int a = ((2 * n - 1) - 1) / 3;
	a++;
	cout << a << endl;
	int b = 0;
	for (int i = 0; i < a; i++) {
		cout << i + 1 << " " << b + 1 << endl;
		b += 2;
		if (b >= a) b = 1;
	}
	
}