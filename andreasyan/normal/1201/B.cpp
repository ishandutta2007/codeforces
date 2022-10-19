#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

bool stg()
{
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += a[i];
    if (sum % 2 == 1)
        return false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > sum / 2)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    if (stg())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}