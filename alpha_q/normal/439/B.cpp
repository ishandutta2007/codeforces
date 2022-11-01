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
#define MAX 100005

int main() {
    i64 n, x, ret = 0, i, A[MAX];
    scanf("%I64d %I64d", &n, &x);
    for (i = 1; i <= n; i++) scanf("%I64d", A + i);
    sort (A + 1, A + n + 1);
    for (i = 1; i <= n; i++) ret += A[i] * max((i64) 1, x--);
    printf("%I64d", ret);
    return 0;
}