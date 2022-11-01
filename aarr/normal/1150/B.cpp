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
int d[55][55];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == '#') {
				d[i][j]++;
			}
			if (d[i][j] == 2) {
				cout << "No";
				return 0;
			}
			if (d[i][j] == 0) {
				if (j % n <= 1 || i >= n - 1) {
					cout << "No";
					return 0;
				}
				d[i + 1][j]++;
				d[i + 1][j - 1]++;
				d[i + 1][j + 1]++;
				d[i + 2][j]++;
			}
		}
	}
	cout << "Yes";
}