/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define checkbit(n, b) ((n >> b) & 1)
#define gcd __gcd
#define bitcount __bultin_popcount
#define inf (int) 2e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007

i64 n, root, val, rem;

int main () {
	cin >> n;
	root = floor ((sqrt(1.0 + 8.0 * n) - 1.0)/2.0);
	val = root * (root + 1) / 2;
	if (n == val) --root;
	val = root * (root + 1) / 2;
	rem = n - val;
	cout << rem << endl;
	return 0;
}