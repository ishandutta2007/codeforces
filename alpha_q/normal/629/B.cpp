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
#define MAX 5005

struct dat {
    char gen;
    int l, r;
};

dat A[MAX];
int n, i, j, m, f, ret;

int main() {
    cin >> n;
    for (i = 1; i <= n; i++) cin >> A[i].gen >> A[i].l >> A[i].r;

    ret = 0;
    for (i = 1; i <= 366; i++) {
        m = f = 0;
        for (j = 1; j <= n; j++) {
            if (A[j].l <= i && i <= A[j].r) {
                if (A[j].gen == 'M') m++;
                else f++;
            }
        }
        ret = max(ret, 2 * min(m, f));
    }

    cout << ret << endl;
    return 0;
}