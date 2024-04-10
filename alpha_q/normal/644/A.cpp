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

const int N = 105;

int n, a, b, r[N][N];

int main () {
    cin >> n >> a >> b;
    if (a * b < n) {
        cout << -1 << endl;
        return 0;
    }

    int x = (n + 1)/2, y = n - x;

    int row = 1, num = 1;
    while (x) {
        for (int i = (row & 1 ? 1 : 2); x && i <= b; i += 2)
            r[row][i] = num, num += 2, x--;
        row++;
    }

    row = 1, num = 2;
    while (y) {
        for (int i = (row & 1 ? 2 : 1); y && i <= b; i += 2)
            r[row][i] = num, num += 2, y--;
        row++;
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) cout << r[i][j] << " ";
        cout << endl;
    }
    return 0;
}