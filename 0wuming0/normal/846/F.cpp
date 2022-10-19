#include"bits/stdc++.h"
using namespace std;
//int a[1000006];
#define ll long long
vector<int>v[1000006];
int save[1000006],nn;
ll sum[1000006];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        v[t].push_back(i);
    }
    ll ans=0;
    for(int i=1;i<=1e6;i++)
    {
        //nn=v[i].size();
        nn=0;
        for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
        {
            save[nn++]=*it;
        }
        for(int j=nn-1;j>=0;j--)
        {
            sum[j]=n-save[j]+1;
        }//if(i==2)cout<<sum[0]<<" "<<sum[1]<<endl;
        for(int j=nn-2;j>=0;j--)sum[j]+=sum[j+1];
        if(0<nn-1)ans+=(save[0])*sum[1];
        for(int j=1;j<nn-1;j++)
        {
            ans+=(save[j]-save[j-1])*sum[j+1];
        }
    }
    ll s=0;
    for(int i=2;i<=n;i++)s+=i*(ll)(n+1-i);
    ans=s-ans;
    ans*=2;
    ans+=n;
    printf("%.15lf\n",(double)ans/(double)n/(double)n);;
    return 0;
}
/*
2
3 4
*/