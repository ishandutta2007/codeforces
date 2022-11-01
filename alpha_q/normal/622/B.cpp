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

int h, m, t, p, q, a;

int main () {
	scanf ("%d:%d", &h, &m);
	scanf ("%d", &a);
	t = (h * 60 + m + a) % 1440;
	p = t / 60, q = t % 60;
	printf ("%02d:%02d\n", p, q);
	return 0;
}