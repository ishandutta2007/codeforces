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

int main()
{
    int a, b, c, x, y, z, up = 0, down = 0;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);
    x > a ? up += x - a : down += (a - x)/2;
    y > b ? up += y - b : down += (b - y)/2;
    z > c ? up += z - c : down += (c - z)/2;
    printf("%s\n", down >= up ? "Yes" : "No");
    return 0;
}