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
#define inf (i64) 2e18
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007
#define MAX 100005

double Ret = 0.0, prob;
pair <i64, i64> A[MAX];
i64 n, p, l, r, a, b, c, d, i;

int main () {
	cin >> n >> p;
	for (i = 1; i <= n; i++) {
		cin >> l >> r;
		a = floor(r * 1.0 / p);
		a -= floor((l - 1) * 1.0 / p);
		b = r - l + 1 - a;
		A[i] = make_pair(a, b);
	} A[n + 1] = A[1];
	for (i = 1; i <= n; i++) {
		a = A[i].first, b = A[i].second;
		c = A[i + 1].first, d = A[i + 1].second;
		prob = 2000.0000000 * (double) (b * c * 1.0 + c * a * 1.0 + a * d * 1.0) / ((a + b) * (c + d) * 1.0);
		Ret += prob;
	}
	printf("%0.12lf\n", Ret);
    return 0;
}