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
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;
		if (n0 + n1) {
			for (int i = 1; i <= n0 + 1; i++) {
				cout << 0;
			}
			for (int i = 1; i <= n1; i++) {
				cout << i % 2;
				if (i == 1) {
					for (int j = 1; j <= n2; j++) {
						cout << 1;
					}
				}
			}
		}
		else {
			for (int i = 1; i <= n2 + 1; i++) {
				cout << 1;
			}
		}
	/*	else {
			for (int i = 1; i < n2; i++) {
				cout << n2;
			}
			for (int i = 1; i <= n1; i++) {
				cout << 1 - i % 2;
			}
		}*/
		cout << endl;
	}

	return 0;
}