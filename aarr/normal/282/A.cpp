#include <iostream>
using namespace std;


const int N = 105;
bool a[N], b[N];
int main() {
	int n, x = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[1] == '+') {
			x++;
		}
		else {
			x--;
		}
	}
	cout << x;
	return 0;
}