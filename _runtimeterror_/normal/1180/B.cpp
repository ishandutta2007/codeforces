#include<iostream>
using namespace std;

int a[100005];

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        if(a[i]>=0)
            a[i]=-a[i]-1;
    }
    if(n&1)
    {
        int id = -1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]==-1)continue;
            if(id==-1 || a[i]<a[id])
                id = i;
        }
        if(id==-1)
            id = 1;
        a[id] = -a[id] - 1;
    }

    for(int i=1;i<=n;++i)
        printf("%d ",a[i]);
}