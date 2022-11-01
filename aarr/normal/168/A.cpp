#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];

int main() {
	int n, x, y, ans = 0;
	cin >> n >> x >> y;
	while (x * 100 < n * y) {
		x++;
		ans++;
	}
	cout << ans;
}