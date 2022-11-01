#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a=1;
        for(int i=1;i<=28;i++)
        {
            a+=(1<<i);
            if((n%a)==0)
            {
                printf("%d\n",n/a);
                break;
            }
        }
    }
    return 0;
}