#include"bits/stdc++.h"
using namespace std;
int num[200005];
int n,m;
int check(int x)
{
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(num[i]>x)ans+=x;
        else ans+=num[i]+(x-num[i])/2;
    }
    if(ans>=m)return 1;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=n;i++)num[i]=0;
        for(int i=0;i<m;i++)
        {
            int a;
            scanf("%d",&a);
            num[a]++;
        }
        sort(num+1,num+n+1);
        int l=-1,r=5e5;
        while(l+1!=r)
        {
            int m=l+r>>1;
            if(check(m))r=m;
            else l=m;
        }
        cout<<r<<endl;
    }
    return 0;
}