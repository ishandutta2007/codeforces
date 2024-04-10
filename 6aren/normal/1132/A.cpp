#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == d && a != 0) cout << 1; 
	else if (a == d && a == 0 && c == 0) cout << 1;
	else cout << 0;
	return 0;
}