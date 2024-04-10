#include <iostream>
#include <algorithm>
using namespace std;

int a[300 * 1000 + 5];
int main() {
	int n;
	string s;
	cin >> n >> s;
	int mini = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') {
			mini = i;
		}
	}
	cout << mini + 1;
}