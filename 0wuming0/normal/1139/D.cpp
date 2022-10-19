#include"bits/stdc++.h"
using namespace std;
int prime[150005];
long long p[150005],nn;
long long mod=1e9+7;
long long dev[150005];
int main()
{
dev[1]=1;
for(int i=2;i<150005;i++)
{
dev[i]=(mod-mod/i)*dev[mod%i]%mod;
}
 for(int i=2;i<150005;i++)
if(prime[i]==0)
{for(int j=2;i*j<150005;j++)prime[i*j]=i;
p[nn++]=i;
}
 int m;
 cin>>m;
 long long ans=1;
int pos[7];
 for(int num=0;num<6;num++)
{//cout<<num<<endl;
//for(int i=0;i<num;i++)pos[i]=i;
pos[0]=-1;
for(int j=0;j>=0;)
{pos[j]++;
long long now=1;
for(int i=0;i<j;i++)now*=p[pos[i]];
for(int i=j;i<=num;i++)now*=
p[pos[i]=pos[j]+i-j];
//cout<<j<<"  "<<now<<endl;
if(now>m)j--;
else if(j!=num)pos[++j]--;
else
{
long long t=m/now;
if(num%2)ans-=t*dev[m-t]%mod;
else ans+=t*dev[m-t]%mod;
ans%=mod;
if(ans<0)ans+=mod;
}
}
}
cout<<ans<<endl;
 return 0;
}