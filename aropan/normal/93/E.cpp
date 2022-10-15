#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXK = 101;
const int MAXF = 200001;

int a[MAXK];
long long f[MAXK][MAXF];
long long n;
int k;

long long rec(int m, long long n)
{
    if (n == 0)
        return 0;

    if (m == k)
        return n;

    if (MAXF <= n)
        return rec(m + 1, n) - rec(m + 1, n / a[m]);

    if (f[m][n] == -1) f[m][n] = rec(m + 1, n) - rec(m + 1, n / a[m]);
    return f[m][n];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    sort(a, a + k);
    reverse(a, a + k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < MAXF; j++)
            f[i][j] = -1;

    cout << rec(0, n) << endl;
    return 0;
}