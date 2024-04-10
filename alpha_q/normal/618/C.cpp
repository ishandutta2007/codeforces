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
#define inf (i64) 9e18
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007
#define MAX 100005

i64 X[MAX], Y[MAX], n, i, id, dist, Ret, cmp = inf, temp;

i64 Area (i64 p, i64 q, i64 r, i64 s, i64 t, i64 u) {
    return abs (p * (s - u) + r * (u - q) + t * (q - s));
}

i64 SqDist (i64 p, i64 q, i64 r, i64 s) {
    return (p - r) * (p - r) + (q - s) * (q - s);
}

int main () {
    cin >> n;
    for (i = 1; i <= n; i++) cin >> X[i] >> Y[i];
    cout << "1 ";
    for (i = 2; i <= n; i++) {
        temp = SqDist(X[1], Y[1], X[i], Y[i]);
        if (temp < cmp) cmp = temp, id = i;
    }
    cout << id << " "; cmp = inf;
    for (i = 2; i <= n; i++) {
        if (i == id) continue;
        temp = Area(X[1], Y[1], X[id], Y[id], X[i], Y[i]);
        if (temp && temp < cmp) cmp = temp, Ret = i;
    }
    cout << Ret << endl;
    return 0;
}