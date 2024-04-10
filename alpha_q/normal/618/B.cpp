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
#define MAX 60

vector <int> V;
int A[MAX][MAX], n, i, j, Ans[MAX], Freq[MAX];

int main () {
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> A[i][j];
    for (i = 1; i <= n; i++) {
        memset (Freq, 0, sizeof Freq);
        for (j = 1; j <= n; j++) ++Freq[A[i][j]];
        for (j = 1; j <= n; j++) {
            if (Freq[j] >= 2) {
                Ans[i] = j;
                break;
            }
        }
        if (j > n) V.push_back(i);
    }
    if (!V.empty()) Ans[V[0]] = n - 1, Ans[V[1]] = n;
    for (i = 1; i <= n; i++) cout << Ans[i] << " ";
    return 0;
}