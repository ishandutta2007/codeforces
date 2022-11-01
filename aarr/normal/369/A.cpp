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
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			m--;
			if (m < 0) {
				ans++;
			}
		}
		else {
			if (k > 0) {
				k--;
			}
			else {
				if (m > 0) {
					m--;
				}
				else {
					ans++;
				}
			}
		}
	}
	cout << ans;
}