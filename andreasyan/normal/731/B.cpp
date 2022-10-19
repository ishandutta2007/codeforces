#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
            a[i] = 0;
        else
        {
            a[i] = 0;
            --a[i + 1];
            if (a[i + 1] < 0)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}