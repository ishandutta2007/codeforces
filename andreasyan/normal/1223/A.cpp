#include <bits/stdc++.h>
using namespace std;

int main()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x;
        scanf("%d", &x);
        for (int i = 0; ; ++i)
        {
            if ((x + i) % 2 == 0 && (x + i) / 2 > 1)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}