#include"bits/stdc++.h"
using namespace std;
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=n;i>=1;i--)
        {
            int now=i;
            for(now=i+1;now>=1;now--)if(a[i]%now!=0)break;
            if(now==0)
            {
                printf("NO\n");
                goto ed;
            }
        }
        printf("YES\n");
        ed:;
    }
    return 0;
}