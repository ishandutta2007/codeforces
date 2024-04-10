#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n,m;
char a[N],b[N];

int dp[N];
int p[N];
int main()
{
    cin>>a>>b;
    n=strlen(a);
    m=strlen(b);
    if(m>n)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<int> t;
    for(int i=0;i<m-1;++i)
    {
        bool z=true;
        for(int j=0,k=m-1-i;j<=i;++j,++k)
        {
            if(b[j]!=b[k])
            {
                z=false;
                break;
            }
        }
        if(z)
            t.push_back(i+1);
    }
    for(int i=m-1;i<n;++i)
    {
        bool z=true;
        for(int j=i,k=m-1;k>=0;--j,--k)
        {
            if(a[j]==b[k] || a[j]=='?')
                continue;
            z=false;
        }
        if(z)
        {
            if(i-m>=0)
            {
                dp[i]=p[i-m]+1;
                for(int j=0;j<t.size();++j)
                {
                    dp[i]=max(dp[i-m+t[j]]+1,dp[i]);
                }
            }
            else
                dp[i]=1;
        }
        p[i]=max(p[i-1],dp[i]);
    }
    cout<<p[n-1]<<endl;
    return 0;
}