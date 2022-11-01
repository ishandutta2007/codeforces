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
#define MAX 1000

bool G[MAX + 5][MAX + 5];
i64 n, i, j, x, y, k, Ret = 0, temp;

int main () {
	memset (G, 0, sizeof G);
    cin >> n; while (n--) {
        cin >> x >> y;
        G[x][y] = true;
    }
    for (k = 1; k <= MAX; k++) {
    	temp = 0;
    	for (i = k, j = 1; i <= MAX && j <= MAX; i++, j++)
    		if (G[i][j]) ++temp;
    	Ret += temp * (temp - 1) / 2;
    }
    for (k = 2; k <= MAX; k++) {
    	temp = 0;
    	for (j = k, i = 1; j <= MAX && i <= MAX; j++, i++)
    		if (G[i][j]) ++temp;
    	Ret += temp * (temp - 1) / 2;
    }
    for (k = 1; k <= MAX; k++) {
    	temp = 0;
    	for (j = k, i = 1; j >= 1 && i <= MAX; j--, i++)
    		if (G[i][j]) ++temp;
    	Ret += temp * (temp - 1) / 2;
    }
    for (k = 2; k <= MAX; k++) {
    	temp = 0;
    	for (j = k, i = MAX; j <= MAX && i >= 1; j++, i--)
    		if (G[i][j]) ++temp;
    	Ret += temp * (temp - 1) / 2;
    }
    cout << Ret << endl;
    return 0;
}