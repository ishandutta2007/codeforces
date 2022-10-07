#include <iostream>

using namespace std;
int a[1000][1000];
int b[1000];

int main()
{
    int n, x, res = 0, i, k, j;
    cin >> n;
    i = 1;
    while (res + i <= n)
    {
        res += i;
        i++;
    }
    k = i;
    x = 0;
    cout << k << "\n";
    for (i = 0; i < k - 1; i++)
        for (j = i + 1; j < k; j++)
        {
            x++;
            a[i][b[i]++] = x;
            a[j][b[j]++] = x;
        }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < b[i]; j++)
            cout << a[i][j] << " ";

        cout << "\n";
    }
    return 0;
}