#include"bits/stdc++.h"
using namespace std;
int a[1005];
int ans[1005][2],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        nn=0;
        for(int i=n;i>1;i--)
        {
            int b=a[i],bi=i;
            for(int j=i-1;j>0;j--)if(a[j]>b)
            {
                b=a[j];
                bi=j;
            }
            if(bi!=i)
            {
                for(int l=bi;l<i;l++)swap(a[l],a[l+1]);
                ans[nn][0]=bi;
                ans[nn++][1]=i;
            }
        }
        printf("%d\n",nn);
        for(int i=0;i<nn;i++)printf("%d %d 1\n",ans[i][0],ans[i][1]);
    }
    return 0;
}