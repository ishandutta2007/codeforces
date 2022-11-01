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

i64 Num, i, n, temp = inf, Ret = 0;

int main () {
    cin >> n; while (n--) {
        cin >> Num; Ret += Num;
        if (Num & 1) temp = min (temp, Num);
    }
    if (Ret & 1) Ret -= temp;
    cout << Ret << endl;
    return 0;
}