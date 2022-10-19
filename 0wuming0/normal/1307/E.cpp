#include"bits/stdc++.h"
using namespace std;
long long mod=1e9+7;
vector<int>l[5005],r[5005];
int s[5005];
long long num[5005][4];
int a[5005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int f,h;
        cin>>f>>h;
        for(int j=1,k=0;j<=n;j++)
        {
            if(a[j]==f)
            {
                k++;
                if(k==h)
                {
                    l[j].push_back(i);
                }
            }
        }
        for(int j=n,k=0;j>=1;j--)
        {
            if(a[j]==f)
            {
                k++;
                if(k==h)
                {
                    r[j].push_back(i);
                    s[i]|=2;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)for(auto j:r[i])
    {
        num[a[i]][2]++;
    }
    long long ans=0,temp=1,sum=0;
    int ss=0;
    for(int i=1;i<=n;i++)
    {//cout<<"??"<<i<<" "<<num[i][1]<<" "<<num[i][2]<<" "<<num[i][3]<<endl;
        if(num[i][1]+num[i][2]+num[i][3])
        {
            if(num[i][1]+num[i][2]+num[i][3]==1)
            {
                ss++;
                if(num[i][3]==1)
                {
                    temp=temp*2%mod;
                }
            }
            else if(num[i][1]+num[i][3]==0)
            {
                ss++;
                temp=temp*num[i][2]%mod;
            }
            else if(num[i][2]+num[i][3]==0)
            {
                ss++;
                temp=temp*num[i][1]%mod;
            }
            else
            {
                ss+=2;
                temp=temp*
                (num[i][1]*(num[i][2]+num[i][3])
                 +num[i][3]*(num[i][2]-1+num[i][3]))
                %mod;
            }
        }//cout<<"??"<<i<<" "<<ss<<endl;
    }
    if(ss>sum)
    {
        sum=ss;
        ans=temp;
    }
    else if(ss==sum)
    {
        sum=ss;
        ans+=temp;
    }//cout<<"<<<"<<sum<<" "<<ans<<endl;
    ss=0;
    temp=1;
    for(int i=1;i<=n;i++)
    {
        for(auto j:r[i])
        {
            num[a[i]][s[j]]--;
            s[j]^=2;
            num[a[i]][s[j]]++;
        }
        for(auto j:l[i])
        {
            num[a[i]][s[j]]--;
            s[j]^=1;
            num[a[i]][s[j]]++;
        }
        int c=0;
        for(auto j:l[i])
        {
            if(s[j]==3)c++;
        }
        if(l[i].size()==0)continue;
        int col=a[i];
        temp=
        (l[i].size()-c)*(num[col][2]+num[col][3])
        +c*(num[col][2]-1+num[col][3]);
        ss=2;
        if(temp==0)
        {
            temp=l[i].size();
            ss=1;
        }
        {
            for(int i=1;i<=n;i++)if(i!=col)
            {
                if(num[i][1]+num[i][2]+num[i][3])
                {
                    if(num[i][1]+num[i][2]+num[i][3]==1)
                    {
                        ss++;
                        if(num[i][3]==1)
                        {
                            temp=temp*2%mod;
                        }
                    }
                    else if(num[i][1]+num[i][3]==0)
                    {
                        ss++;
                        temp=temp*num[i][2]%mod;
                    }
                    else if(num[i][2]+num[i][3]==0)
                    {
                        ss++;
                        temp=temp*num[i][1]%mod;
                    }
                    else
                    {
                        ss+=2;
                        temp=temp*
                        (num[i][1]*(num[i][2]+num[i][3])
                         +num[i][3]*(num[i][2]-1+num[i][3]))
                        %mod;
                    }
                }
            }
            if(ss>sum)
            {
                sum=ss;
                ans=temp;
            }
            else if(ss==sum)
            {
                sum=ss;
                ans+=temp;
            }
            ss=0;
            temp=1;
        }//cout<<"<<<"<<" "<<i<<" "<<sum<<" "<<ans<<endl;
    }
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<sum<<" "<<ans<<endl;
    return 0;
}