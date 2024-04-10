#include"bits/stdc++.h"
using namespace std;
bool can[16000005];
bool save[8000005];
int a[2005];
int b[2005];
int s[2005];
int main()
{
    int k,n;
    cin>>k>>n;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=k;i++)
    {
        int t=b[1]-s[i];
        for(int j=1;j<=n;j++)
        {
            save[b[j]+4000000]=1;
        }
        bool flag=1;
        for(int j=1;j<=k;j++)
        {
            if(t+s[j]+4000000>=0&&t+s[j]+4000000<8000005)
            {
                save[t+s[j]+4000000]=0;
            }
        }
        for(int j=1;j<=n;j++)if(save[b[j]+4000000])
        {
            flag=0;
            save[b[j]+4000000]=0;
        }
        if(flag)
        {
            can[t+8000000]=1;
        }
    }
    int ans=0;
    for(int i=0;i<16000005;i++)if(can[i])ans++;
    cout<<ans<<endl;
    return 0;
}