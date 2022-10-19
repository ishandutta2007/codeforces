#include"bits/stdc++.h"
using namespace std;
int a[200005],b[200005];
int pos[200005];
int gcd(int a,int b)
{
    if(a==0||b==0)return a+b;
    return gcd(b,a%b);
}
int main()
{
    int n;
    cin>>n;
    int t=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        pos[i]=i;
    }
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",b+i);
        if(a[i]==0&&b[i]==0)t++;
        else if(a[i]!=0)
        {
            int g=gcd(abs(a[i]),abs(b[i]));
            a[i]/=g;
            b[i]/=g;
            if(a[i]<0)
            {
                a[i]=-a[i];
                b[i]=-b[i];
            }
            pair<int,int>pr;pr.first=b[i],pr.second=a[i];
            if(mp.find(pr)==mp.end())mp[pr]=1;
            else mp[pr]++;
        }
    }
    int last=1;
    int ans=0;
    for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        ans=max(it->second,ans);
    }
    cout<<ans+t<<endl;
    return 0;
}