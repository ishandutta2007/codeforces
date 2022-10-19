#include"bits/stdc++.h"
using namespace std;
int a[200005];
int pos[200005];
int now;
void pr(int n)
{
    while(1)
    {
        if(pos[now]<=n)
        {
            if(pos[now]==1)
            {
                for(int i=1;i<=n;i++)
                {
                    if(a[i]-1)putchar(' ');
                    printf("%d",a[i]);
                }
            }
            else
            {
                if(a[pos[now]]-1)putchar(' ');
                printf("%d",a[pos[now]]);
                int i=pos[now]+1;
                pr(pos[now]-1);
                for(;i<=n;i++)
                {
                    printf(" %d",a[i]);
                }
            }
            break;
        }
        else now++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            pos[a[i]]=i;
        }
        now=1;
        pr(n);
        putchar(10);
    }
    return 0;
}