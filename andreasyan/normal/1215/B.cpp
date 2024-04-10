#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

int p[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + (a[i] < 0);
    long long ansm = 0, ansp = 0;
    int z = 1, k = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (p[i] % 2 == 0)
        {
            ansp += z;
            ansm += k;
        }
        else
        {
            ansp += k;
            ansm += z;
        }
        if (p[i] % 2 == 0)
            ++z;
        else
            ++k;
    }
    cout << ansm << ' ' << ansp << endl;
    return 0;
}