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
	cin >> n >> a[0] >> a[1] >> a[2];
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int x = min(a[0], a[1]);
	int y = min(x, a[2]);
	cout << (n - 2) * y + x;
}