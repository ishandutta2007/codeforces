#include<bits/stdc++.h>
#define LL long long
#define mod 998244353244353LL
using namespace std;
int n,n2,m,now,maxr;
LL ans=0;
int R[502],res[252];
LL a[502],to[26];
bool b[502];
bool cnt[252][26];
LL Hs[252][252];
char s[252][252];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL RND()
{
	LL res=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	return res<0? -res:res;
}
int main()
{
	srand(time(NULL)),read(n),read(m),n2=(n<<1);
	for(int i=0;i<26;++i)to[i]=RND();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)Hs[i][j]=(Hs[i][j-1]+to[s[i][j]-='a'])%mod;
	}
	for(int i=1;i<n;++i)a[2*i]=-1,b[2*i]=1;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			res[j]=0;
			for(int k=0;k<26;++k)cnt[j][k]=0;
		}
		for(int j=i,t;j<=m;++j)
		{
			now=maxr=0,t=((j-i+1)&1);
			for(int k=1;k<=n;++k)a[2*k-1]=(Hs[k][j]-Hs[k][i-1]+mod)%mod,res[k]+=((cnt[k][s[k][j]]^=1)? 1:-1),b[2*k-1]=(res[k]<=t);
			for(int k=1;k<n2;++k)
			{
				if(!b[k])continue;
				if(k<=maxr)R[k]=min(R[2*now-k],maxr-k);else R[k]=1;
				while(k-R[k]>0 && k+R[k]<n2 && b[k-R[k]] && b[k+R[k]] && a[k-R[k]]==a[k+R[k]])++R[k];
				if(k+R[k]-1>maxr)now=k,maxr=k+R[k]-1;
				ans+=(R[k]+(k&1))/2;
			}
		}
	}
	return 0&printf("%lld",ans);
}