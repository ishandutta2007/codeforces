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

bool cmp (int x, int y) {return x > y ? 1 : 0;}

int main () {
	int n, m, S[105], k = 0; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> S[i];
	sort(S, S + n, cmp); while (m > 0) m -= S[k], k++; 
	printf("%d\n", k);
    return 0;
}