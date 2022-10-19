#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
char a[N];

int main()
{
    scanf("%d %s", &n, a);
    int ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] == 'a' && a[i + 1] == 'a')
        {
            ++ans;
            a[i] = 'b';
        }
        else if (a[i] == 'b' && a[i + 1] == 'b')
        {
            ++ans;
            a[i] = 'a';
        }
    }
    printf("%d\n%s\n", ans, a);
    return 0;
}