#include <iostream>
using namespace std;

int a[5005];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	bool ans = false;
	for (int i = 1; i <= n; i++) {
		if (a[a[a[i]]] == i)
			ans = true;
	}
	if (ans)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}