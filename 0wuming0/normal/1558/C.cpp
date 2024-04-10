#include"bits/stdc++.h"
using namespace std;
#pragma GCC optimize("O3")
int a[2500];
int ans[6250005],nn;
void solve(int k)
{
    ans[nn++]=k;
    for(int i=1,j=k;i<j;i++,j--)
    {
        swap(a[i],a[j]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=1;i<=n;i++)if((i+a[i])%2)
        {
            cout<<-1<<endl;
            goto ne;
        }
        //5*(n/2)
        nn=0;
        for(int i=n;i>1;i-=2)
        {
            int k=0;
            for(k=1;;k++)if(a[k]==i)break;
            solve(k);//cout<<"<<";for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
            for(k=1;;k++)if(a[k]==i-1)break;
            //cout<<"??"<<k<<" "<<a[k+1]<<endl;
            solve(k-1);//cout<<"<<";for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
            solve(i);//cout<<"<<";for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
            for(k=1;;k++)if(a[k]==i)break;
            solve(k);//cout<<"<<";for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
            solve(i);//cout<<"<<";for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
        }
        //cout<<"<<"<<5*(n/2)<<endl<<"<<";for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
        ne:;
    }
    return 0;
}
/*

*/