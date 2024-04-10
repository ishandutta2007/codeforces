#include <iostream>
using namespace std;

int x[105];
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < a; i++) {
		int ashghal;
		cin >> ashghal;
	}
	for (int i = 0; i < b; i++) {
		int y;
		cin >> y;
		x[y] = 1;	
	}
	for (int i = 1; i <= n; i++) {
		cout << x[i] + 1 << " ";
	}
	return 0;
}