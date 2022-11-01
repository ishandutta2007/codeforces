#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;

bool mark[N + 5];
vector <int> pr;
int main() {
	mark[1] = true;
	int n;
	cin >> n;
	if (n == 2) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		if (mark[i] == false) {
			pr.push_back(i);
			for (int j = i * 2; j <= N; j += i) {
				mark[j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int x = pr[i + 3];
		if (i % 3 == 0) {
			x *= 2 * 3;
		}
		if (i % 3 == 1) {
			x *= 2 * 5;
		}
		if (i % 3 == 2) {
			x *= 3 * 5;
		}
		cout << x << endl;
	}
	return 0;
}