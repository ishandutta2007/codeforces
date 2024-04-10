#include <iostream>
using namespace std;

int mark[100005];
int main() {
	int n, m = 1;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (mark[i] == 0) {
			mark[i] = m;
			for (int j = i * 2; j <= n; j += i) {
				mark[j] = m;
			}
			m++;
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << mark[i] << " ";
	}
	return 0;
}