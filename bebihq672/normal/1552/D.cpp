#include<bits/stdc++.h>
using namespace std;

int a[22];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        bool flag = 0;
        int _3n = 1;
        for(int i = 1; i <= n; i++)
            _3n *= 3;
        for(int i = 1; i < _3n; i++)
        {
            int sum = 0, ii = i;
            for(int j = 1; j <= n; j++)
            {
                if(ii % 3 == 1)
                    sum += a[j];
                else if(ii % 3 == 2)
                    sum -= a[j];
                ii /= 3;
            }
            if(sum == 0)
            {
                flag = 1;
                puts("YES");
                break;
            }
        }
        if(!flag)
            puts("NO");
    }
    return 0;
}