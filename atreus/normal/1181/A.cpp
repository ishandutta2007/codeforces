#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	ll x, y, z;
	cin >> x >> y >> z;
	if (x / z + y / z == (x + y) / z)
		return cout << (x + y) / z << " " << 0 << '\n', 0;
	ll t = min(z - (x % z), z - (y % z));
	cout << (x + y) / z << " " << t << '\n';
}