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

int n, i, siz = 0; vector <int> V;

int main () {
    cin >> n;
    for (i = 1; i <= n; i++) {
        V.push_back(1); ++siz;
        if (siz >= 2)
            while (V[siz - 1] == V[siz - 2])
                V.pop_back(), V[siz - 2]++, siz--;
    }
    for (i = 0; i < siz; i++) cout << V[i] << " ";
    return 0;
}