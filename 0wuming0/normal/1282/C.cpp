#include"bits/stdc++.h"
using namespace std;
struct _
{
    int op;
    int t;
}pm[200005];
int n,lim;
int a,b;
bool cmp(_ x,_ y)
{
    return x.t<y.t;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>lim>>a>>b;
        int numa=0,numb=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&pm[i].op);
            if(pm[i].op==0)numa++;
            else numb++;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&pm[i].t);
        }
        int ans=0;
        int nowt=0;
        sort(pm,pm+n,cmp);
        for(int i=0;i<=n;i++)
        {
            if(nowt>lim)break;
            if(i==n)
            {
                ans=n;
                break;
            }
            if(nowt<pm[i].t)
            {
                int save=i;
                int nn=pm[i].t-nowt-1;
                int num=nn/a;
                if(num<=numa)save+=num;
                else
                {
                    nn-=numa*a;
                    num=nn/b;
                    save+=numa;
                    save+=min(numb,num);
                }
                ans=max(ans,save);
            }
            if(pm[i].op==0)numa--,nowt+=a;
            else numb--,nowt+=b;
        }
        cout<<ans<<endl;
    }
    return 0;
}