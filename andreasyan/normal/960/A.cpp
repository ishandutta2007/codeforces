#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n;
char a[N];

bool solv()
{
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    int q[3] = {};
    for (int i = 0; i < n; ++i)
    {
        q[a[i] - 'a']++;
    }
    if (!q[0] || !q[1])
        return false;
    if (q[2] != q[0] && q[2] != q[1])
        return false;
    return true;
}

int main()
{
    scanf(" %s", a);
    n = strlen(a);
    if (solv())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}