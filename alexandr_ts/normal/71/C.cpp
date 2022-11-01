#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[100001], b[100001];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int cur = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
        {
            b[cur] = i;
            cur++;
        }
    int err = 0;
    for (int k = n / 3; k >= 1; k--)
        if (n % k == 0)
        for (int j = 1; j <= k; j++)
        {
            cur = j;
            err = 0;
            while (err == 0 && cur <= n)
            {
                if (a[cur] != 1)
                {
                    err = 1;
                    break;
                }
                cur += k;
            }
            if (err == 0)
            {
                cout << "YES";
                exit(0);
            }
        }
    cout << "NO";
    return 0;
}