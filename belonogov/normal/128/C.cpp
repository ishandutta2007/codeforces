#include <iostream>

using namespace std;
const long long p = 1e9 + 7;
long long a[2011][2011];


int main()
{
    int n, m, k, d, i, j;
    cin >> n >> m >> k;
    d = max(n, m);
    a[0][0] = 1;
    for (i = 1; i <= d; i++)
        for (j = 0; j <= i; j++)
        {
            a[i][j] = a[i - 1][j];
            if (j > 0)
                a[i][j] = (a[i][j] + a[i - 1][j - 1]) % p;

        }
        cout << (a[n - 1][k * 2] * a[m - 1][k * 2]) % p;
    return 0;
}