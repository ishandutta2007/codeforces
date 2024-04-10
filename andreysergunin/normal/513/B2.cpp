#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n, m, a[MAXN], st[MAXN];
    scanf("%I64d %I64d", &n, &m);
    st[0] = 1;
    for (int i = 1; i <= n; i++)
        st[i] = st[i - 1] * 2;
    int l = 0;
    int r = n;
    for (int i = 1; i < n; i++)
    {
        if (m > st[n - i - 1])
        {
            a[r - 1] = i;
            r--;
            m -= st[n - i - 1];
        }
        else
        {
            a[l] = i;
            l++;
        }
    }
    a[l] = n;
    for (int i = 0; i < n; i++)
        printf("%I64d ", a[i]);
    return 0;
}