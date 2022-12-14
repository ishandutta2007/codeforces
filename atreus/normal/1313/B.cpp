#include <bits/stdc++.h>

using namespace std;

const int maxn = 12345;

int a[5];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, x, y;
		cin >> n >> x >> y;
		int mnm = 0, mxm = 0;
		int X = n - y, Y = n - x;
		mnm = max(x - 1 - min(x - 1, max(0, X - 1)), y - 1 - min(y - 1, max(0, Y - 1)));
		int A = min(x - 1, X), B = min(y - 1, Y);
		mxm = A + B + min(x - A - 1, y - B - 1);
		cout << mnm + 1 << " " << mxm + 1 << '\n';
	}
}