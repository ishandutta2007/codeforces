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
#define mod 100000007

bool Mark[105]; int n, m, x, y, i;

int main() {
	memset(Mark, 0, sizeof Mark);
	scanf("%d %d", &n, &m); while (n--) {
		scanf("%d", &x);
		while (x--) {
			scanf("%d", &y);
			Mark[y] = true;
		}
	}
	for (i = 1; i <= m; i++)
		if (!Mark[i]) {cout << "NO"; return 0;}
	cout << "YES";
    return 0;
}