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

int main () {
    i64 n, a[1005], b[1005];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    i64 ret = 0;
    for (int l = 1; l <= n; l++) {
        i64 A = 0, B = 0;
        for (int r = l; r <= n; r++) A |= a[r], B |= b[r], ret = max(ret, A + B);
    }

    cout << ret << endl;
    return 0;
}