#include <bits/stdc++.h>
using namespace std;

char buf[11];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%s", buf);

    int n = strlen(buf);
    for(int i = 0; i + 2 < n; i++)
    {
        if(((buf[i] - 'A') + (buf[i + 1] - 'A')) % 26 != (buf[i + 2] - 'A'))
        {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    return 0;
}