#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f() {

	ll c[4];
	for (ll &x : c)
		cin >> x;

	if (c[0] != c[3])
		return false;
	if (c[2] && !c[0])
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << f();
	return 0;
}