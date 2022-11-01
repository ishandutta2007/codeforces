#include <iostream>
#include <vector>
using namespace std;

const int N = 1000 * 1000 + 5;

vector <int> vec;
bool b[N];
int main() {
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 2; i <= k; i++) {
		if (k % i == 0) {
			int x = 1;
			while (k % i == 0) {
				k /= i;
				x *= i;
			}
			vec.push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < vec.size(); j++) {
			if (x % vec[j] == 0) {
				b[j] = true;
			}
		}
	}
	bool a = true;
	for (int i = 0; i < vec.size(); i++) {
		a &= b[i];
	}
	if (a) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}