#include"bits/stdc++.h"
using namespace std;
int a[200005];
int ans[200005][2],nn;
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    nn=1;
    for(int i=1;i<n;i++)
    {
        ans[nn][0]=a[0];
        ans[nn][1]=a[i];
        if(a[0]<a[i])
        {
            swap(a[0],a[i]);
        }
        nn++;
    }
    while(q--)
    {
        long long m;
        scanf("%lld",&m);
        if(m<=n-1)
        {
            printf("%d %d\n",ans[m][0],ans[m][1]);
        }
        else
        {
            m=(m-1)%(n-1)+1;
            printf("%d %d\n",a[0],a[m]);
        }
    }
    return 0;
}