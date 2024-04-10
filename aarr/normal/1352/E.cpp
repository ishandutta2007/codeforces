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
		int n, ans = 0;
		cin >> n;
		fill(mark, mark + N, false);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			int s = a[i];
			for (int j = i - 1; j >= 0; j--) {
				s += a[j];
				if (s > n) {
					break;
				}
				mark[s] = true;
			}
		}
		for (int i = 0; i < n; i++) {
			if (mark[a[i]]) {
			//	cout << "73 " << a[i] << endl;
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}