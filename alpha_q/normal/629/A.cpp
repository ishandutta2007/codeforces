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

char A[105][105];
int n, i, j, row, col, ret = 0;

int main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        row = 0;
        for (j = 1; j <= n; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'C') row++;
        }
        ret += row * (row - 1)/2;
    }

    for (i = 1; i <= n; i++) {
        col = 0;
        for (j = 1; j <= n; j++)
            if (A[j][i] == 'C') col++;
        ret += col * (col - 1)/2;
    }

    cout << ret << endl;
    return 0;
}