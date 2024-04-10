/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
	long long n, a, b, p, q, ans;
	cin >> n >> a >> b >> p >> q;
	long long lcm = a * (b/__gcd(a, b));
	ans = p * (n/a) + q * (n/b) - min(p, q) * (n/lcm);
	cout << ans << endl;	
	return 0;
}