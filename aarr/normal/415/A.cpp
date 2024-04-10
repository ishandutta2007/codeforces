#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 305;
int ans[N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		for (int j = x; j <= n; j++) {
			if (!ans[j]) {
				ans[j] = x;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}