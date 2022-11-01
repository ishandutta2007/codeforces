#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 305;
int cnt[N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int p, n;
	cin >> p >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (cnt[x % p]) {
			cout << i;
			return 0;
		}
		cnt[x % p]++;
	}
	cout << -1;
}