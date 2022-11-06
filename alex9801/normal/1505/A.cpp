#include <bits/stdc++.h>
using namespace std;

char buf[100000];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    while(fgets(buf, 100000, stdin))
    {
        int n = strlen(buf);
        while(n && isspace(buf[n - 1]))
        {
            buf[n - 1] = '\0';
            n--;
        }
        if(n == 0)
            return 0;

        if(strcmp(buf, "Is it rated?") == 0)
            printf("NO\n");
        else
            printf("YES\n");
        fflush(stdout);
    }
    return 0;
}