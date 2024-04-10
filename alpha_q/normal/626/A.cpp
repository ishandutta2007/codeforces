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
#define exp 1000000005
#define MAX 300005

int n, k, i, j, X, Y, Ret; string S, T;

int main () {
	cin >> n >> S; Ret = 0;
	for (k = 1; k <= n; k++) {
		for (i = 0; i <= n - k; i++) {
			T = S.substr(i, k);
			X = 0, Y = 0;
			for (j = 0; j < k; j++) {
				if (T[j] == 'U') Y++;
				if (T[j] == 'D') Y--;
				if (T[j] == 'L') X--;
				if (T[j] == 'R') X++;
			}
			if (X == 0 && Y == 0) ++Ret;
		}
	}
	cout << Ret << endl;
	return 0;
}