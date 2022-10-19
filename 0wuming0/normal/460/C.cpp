#include"bits/stdc++.h"
using namespace std;
int n,m,w;
int a[100005];
int ad[200105];
bool solve(int x)
{
    for(int i=0;i<200105;i++)ad[i]=0;
    int now=m;
    for(int i=1;i<=n;i++)
    {
        ad[i]+=ad[i-1];
        int nd=x-ad[i];
        while(a[i]<nd)
        {
            if(now==0)return 0;
            nd--;
            ad[i]++;
            ad[i+w]--;
            now--;
        }
    }
    return 1;
}
int main()
{
    cin>>n>>m>>w;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int l=0,r=1e9+1e6;
    while(l+1!=r)
    {//cout<<"<<"<<l<<" "<<r<<endl;
        int x=l+r>>1;
        if(solve(x))l=x;
        else r=x;
    }
    cout<<l<<endl;
    return 0;
}