#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
const int G=3,Gi=332748118;
int n,n1,l=0,t=-1,lim=1;
vector<int> vec;
int r[262144];
LL a[262144],b[262144];
char s[100002];
inline void dfs(int x,int y,int o)
{
	if(x==vec.size())return (void)(b[y]+=o);
	dfs(x+1,y,-o),dfs(x+1,(y+vec[x])%n,o);
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void NTT(LL a[],int o)
{
	for(int i=0;i<lim;++i)if(i<r[i])swap(a[i],a[r[i]]);
	LL W,Wn,tmp;
	for(int i=1;i<lim;i<<=1)
	{
		Wn=Pow(~o? G:Gi,(mod-1)/(i<<1));
		for(int j=0;j<lim;j+=(i<<1))
		{
			W=1;
			for(int k=0;k<i;++k,(W*=Wn)%=mod)tmp=a[j+k],a[j+k]=(tmp+W*a[i+j+k])%mod,a[i+j+k]=(tmp-W*a[i+j+k])%mod;
		}
	}
}
int main()
{
	scanf("%d%s",&n,s),n1=n;
	for(int i=0;i<n;++i)a[i]=(s[i]^48);
	for(int i=2;i*i<=n1;++i)if(!(n1%i))for(vec.push_back(n/i),l+=n/i;!(n1%i);)n1/=i;
	if(n1>1)vec.push_back(n/n1),l+=n/n1;
	for(l=min(l,n),dfs(0,0,1);lim<=n+l;++t)lim<<=1;
	for(int i=1;i<lim;++i)r[i]=((r[i>>1]>>1)|((i&1)<<t));
	NTT(a,1),NTT(b,1);
	for(int i=0;i<lim;++i)(a[i]*=b[i])%=mod;
	NTT(a,-1);
	for(int i=n;i<lim;++i)(a[i%n]+=a[i])%=mod;
	for(int i=0;i<n;++i)if(a[i])return 0&puts("NO");
	return 0&puts("YES");
}