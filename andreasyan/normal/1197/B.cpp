#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int j;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == n)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i <= n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = j - 1; i >= 1; --i)
    {
        if (a[i] > a[i + 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}