#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=200010;
const int mod=1e9+7;
const int inf=2147483647;
const double pi=acos(-1.0);
int read()
{
 int x=0,f=1;char ch=getchar();
 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
 while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
 return x*f;
}
map<LL,int>mp;
int n,a[Maxn],b[Maxn],f[Maxn],s[Maxn];LL sum[Maxn];
void add(int x,int v){for(;x<=n+1;x+=(x&(-x)))s[x]=(s[x]+v)%mod;}
int query(int x){int t=0;for(;x;x-=(x&(-x)))t=(t+s[x])%mod;return t;}
int main()
{
 int T=read();
 while(T--)
 {
  n=read();sum[0]=0;mp.clear();
  for(int i=1;i<=n;i++)a[i]=read();
  a[++n]=0;
  for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(LL)a[i],s[i]=0;s[n+1]=0;
  for(int i=n;i;i--)
  {
   mp[sum[i]]=i;
   int t=mp[sum[i]-a[i]];
   if(t)b[i]=t+1;else b[i]=n+1;
  }
  add(b[1],1);
  for(int i=2;i<=n;i++)
  {
   f[i]=(query(n+1)-query(i-1)+mod)%mod;
   add(b[i],f[i]);
  }
  printf("%d\n",f[n]);
 } 
}