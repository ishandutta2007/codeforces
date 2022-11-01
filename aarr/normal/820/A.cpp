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
	int c, v0, v1, a, l, ans = 1;
	cin >> c >> v0 >> v1 >> a >> l;
//	if (c <= v0) {
//		cout << 1;
//		return 0;
//	}
	c -= v0;
	v0 = min(v0 + a, v1);
	while (c > 0) {
	//	cout << c << " ";
		c -= v0 - l;
		v0 += a;
		v0 = min(v0, v1);
		ans++;
	//	cout << c << endl;
	}
	cout << ans;
	return 0;
}