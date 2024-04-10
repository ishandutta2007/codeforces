#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
vector <int> vec;
deque <int> q;
bool mark[N];

int main() {
	int n, k, x;
	cin >> n >> k;
	if (k != 1) {
		cout << "Yes";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			x = i;
		}
	}
	cin >> a[x];
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}