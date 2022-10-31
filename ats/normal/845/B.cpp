#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt(int i,int a,int b,int c) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	int k = a + b + c;
	if (k < i) {
		k += 9 - a;
		if (k < i) {
			k += 9 - b;
			if (k < i) {
				return 3;
			}
			else {
				return 2;
			}
		}
		else {
			return 1;
		}
	}
	else if (k > i) {
		k -= c;
		if(k > i){
			k -= b;
			if (k > i) {
				return 3;
			}
			else {
				return 2;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int a[6];
	for (int i = 0; i < 6; i++) {
		a[i] = (int)(s[i] - '0');
	}
	int res;
	res = 100000;
	for (int i = 0; i < 28; i++) {
		res = min(res, cnt(i, a[0], a[1], a[2]) + cnt(i, a[3], a[4], a[5]));
	}
	cout << res << endl;
	return 0;
}