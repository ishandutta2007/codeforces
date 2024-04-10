#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 3; i <=n; i++) 
		ans += (i - 1) * i;
	cout << ans;
	return 0;
}