#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int a[10000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k, n, i;
    cin >> n >> k;
    k--;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (k <= i && a[i] == 1)
        {
            cout << i + 1;
            return 0;
        }

    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}