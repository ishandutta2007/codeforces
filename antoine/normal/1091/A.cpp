#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int y, b, r;
	cin >> y >> b >> r;


	int ans = min(y, min(b-1, r-2));
	cout << (ans < 0 ? 0 : 3*ans + 3);
	return 0;
}