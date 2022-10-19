#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100003;

int n,q,s;
int a[N];
int ans[N];
int nex[N];
int last[N];
int main()
{
    //ios_base::sync_with_stdio(false);//,cin.tie(0),cout.tie(0);
    scanf("%d%d",&n,&q);
    //cin>>n>>q;
    s=sqrt(n+0.0);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
        //cin>>a[i];
    for(int i=n;i>=1;--i)
    {
        int j=i+a[i];
        if(j>n)
        {
            ans[i]=1;
            nex[i]=-1;
            last[i]=i;
        }
        else if((j/s)==(i/s))
        {
            ans[i]=ans[j]+1;
            nex[i]=nex[j];
            last[i]=last[j];
        }
        else
        {
            ans[i]=1;
            nex[i]=j;
            last[i]=i;
        }
    }
    for(int ii=0;ii<q;++ii)
    {
        int u;
        scanf("%d",&u);
        //cin>>u;
        if(u==0)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            //cin>>x>>y;
            a[x]=y;
            int b=x/s;
            for(int i=x;(i/s)==b && i>=1;--i)
            {
                int j=i+a[i];
                if(j>n)
                {
                    ans[i]=1;
                    nex[i]=-1;
                    last[i]=i;
                }
                else if((j/s)==(i/s))
                {
                    ans[i]=ans[j]+1;
                    nex[i]=nex[j];
                    last[i]=last[j];
                }
                else
                {
                    ans[i]=1;
                    nex[i]=j;
                    last[i]=i;
                }
            }
        }
        else
        {
            int x;
            scanf("%d",&x);
            //cin>>x;
            int t=0,v;
            for(int i=x;i!=-1;i=nex[i])
            {
                v=last[i];
                t+=ans[i];
            }
            printf("%d %d\n",v,t);
            //cout<<v<<' '<<t<<endl;
        }
    }
    return 0;
}