#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 8005;

int a[N];
vector <int> vec;
deque <int> q;
bool mark[N];

int main() {
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		if (n <= 3) {
			cout << "-1\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (i % 4 == 3) {
				cout << i << " ";
			}
		} 
		for (int i = n; i; i--) {
			if (i % 4 == 1) {
				cout << i << " ";
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i % 4 == 0) {
				cout << i << " ";
			}
		}
		for (int i = n; i; i--) {
			if (i % 4 == 2) {
				cout << i << " ";
			}
		}
		cout << endl;
	}

	return 0;
}