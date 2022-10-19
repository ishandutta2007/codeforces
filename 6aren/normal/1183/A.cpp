#include<bits/stdc++.h>

using namespace std;

int calc(int a) {
	int res = 0;
	while (a != 0) {
		res += a % 10;
		a /= 10;
	}
	return res;
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int n;
	cin >> n;
	for (int i = n; ; i++) {
		if (calc(i) % 4 == 0) {
			cout << i;
			break;
		}
	}
	return 0;
}