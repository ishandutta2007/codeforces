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
#define inf (int)1e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007
#define MAX 100005

int main () {
	i64 i, n, t, two[45]; two[0] = 1;
	for (i = 1; i <= 40; i++) two[i] = two[i - 1] * 2;
	cin >> t; while (t--) {
		cin >> n; i64 ret = n * (n + 1) / 2;
		for (i = 0; two[i] <= n; i++) ret -= two[i + 1];
		cout << ret << endl;
	}
	return 0;
}