#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f() {
	ll x,y,z,a,b,c;
	cin >> x >> y >> z >> a >> b >> c;


	a -= x;
	if(a<0)
		return false;

	return y <= a + b && y + z <= a + b + c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << (f() ? "YES" : "NO");
	return 0;
}