/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
const int mod = 1000000007;

int x, y, n, size;

int a1[1000], b1[1000], c1[1000];

void add(int x2, int y2) {
	for(int i = 0; i < size; i++)
		if(a1[i] * x2 + b1[i] * y2 + c1[i] == 0){
			return;
		}
	int a = y - y2;
	int b = x2 - x;
	int c = x * y2 - x2 * y;
	//cout << a << " " << b << " " << c << endl;
	a1[size] = a;
	b1[size] = b;
	c1[size] = c;
	size++;
}

int main() {

	sync;
	size = 0;
	cin >> n >> x >> y;
	while(n--) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	cout << size << endl;
}