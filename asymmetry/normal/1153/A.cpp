#include <bits/stdc++.h>

using namespace std;

int n, t, m=1000000000, mp, a, b;

int main()
{
    scanf("%d%d", &n, &t);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &a, &b);
        if(a>=t)
        {
            if(m>a)
            {
                m=a;
                mp=i;
            }
        }
        else
        {
            if((t-a)%b)
            {
                if(m>t+b-(t-a)%b)
                {
                    m=t+b-(t-a)%b;
                    mp=i;
                }
            }
            else
            {
                if(m>t)
                {
                    m=t;
                    mp=i;
                }
            }
        }
    }
    printf("%d", mp);
    return 0;
}