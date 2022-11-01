#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define M (111)

ll n,m,mask[N][M],fct[M];
vector <ll> dig;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fct[0]=1;
    for(int i=1;i<20;i++)fct[i]=fct[i-1]*i;
    cin>>n>>m;
    while(n)
        dig.push_back(n%10),n/=10;
    for(int i=0;i<dig.size();i++)
        if(dig[i]!=0)
            mask[(1<<i)][(dig[i]%m)]=1;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<dig.size();j++)
            if(i&(1<<j))
                for(int k=0;k<m;k++)
                    mask[i][(k*10+dig[j])%m]+=mask[i^(1<<j)][k];    
    ll ans=mask[(1<<(dig.size()))-1][0];
    for(int i=0;i<10;i++)
    {
        ll num=0;
        for(int j=0;j<dig.size();j++)
            if(dig[j]==i)
                num++;
        ans/=fct[num];      
    }
    cout<<ans;
    return 0;
}