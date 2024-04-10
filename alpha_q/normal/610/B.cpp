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
#define MAX 400050

i64 Min (i64 x, i64 y) {return x < y ? x : y;}
i64 Max (i64 x, i64 y) {return x > y ? x : y;}

int main () {
	i64 N, i, A[MAX], m = (int)mod, cnt, M; 
	scanf("%I64d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%I64d", A + i);
		m = Min(m, A[i]);
	}
	for (i = 1; i <= N; i++) {
		if (A[i] == m) A[i] = 0, A[N + i] = 0;
		else A[i] = 1, A[N + i] = 1;
	}
	M = 0, cnt = 0;
	for (i = 1; i <= 2 * N; i++) {
		if (A[i] == 1) ++cnt;
		else M = Max(M, cnt), cnt = 0;
	}
	printf("%I64d\n", N * m + M);
	return 0;
}