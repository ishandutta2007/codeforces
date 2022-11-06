#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define all(a) (a).begin(), (a).end()
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k, i, x, y;
	cin >> n >> m >> k;
	for (i = 0; i < k; i++) {
		cin >> x >> y;
		if (x <= 5 || x + 4 >= n || y <= 5 || y + 4 >= m) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}//nekqpq