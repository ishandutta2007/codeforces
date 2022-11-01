#include <iostream>
using namespace std;


const int N = 12;
int a[N];
bool mark[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;
		mark[y] = true;
	}
	for (int i = 0; i < n; i++) {
		if (mark[a[i]])
			cout << a[i] << " ";
	}
	return 0;
}