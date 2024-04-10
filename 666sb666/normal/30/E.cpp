#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');}
typedef unsigned long long ULL;
const int maxn=1e5+5,x=123;
char s[maxn];
int n,l[maxn],pa[maxn],f[maxn][25],ans=0,num,len,pos;
ULL lh[maxn],rh[maxn],xp[maxn];
inline ULL LHASH(int l,int r)
{
	return lh[r]-lh[l-1]*xp[r-l+1];
}
inline ULL RHASH(int l,int r)
{
	return rh[l]-rh[r+1]*xp[r-l+1];
}
inline int query(int l,int r)
{
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	xp[0]=1;
	for(int i=1;i<=n;i++)xp[i]=xp[i-1]*x;
	for(int i=1;i<=n;i++)lh[i]=lh[i-1]*x+s[i]-'a'+3;
	for(int i=n;i;i--)rh[i]=rh[i+1]*x+s[i]-'a'+3;
	int p=1;
	for(int i=n;i;i--)
	{
		ULL tmp=LHASH(i,n);
		while(RHASH(p,p+n-i)!=tmp&&p<=n-(n-i+1)*2+1)p++;
		if(p>n)break;
		if(p+n-i>=i)break;
		l[i]=p;
	}
	for(int i=1;i<=n;i++)
	{
		int m=min(i,n-i+1);
		int l=1,r=m;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(LHASH(i-mid+1,i)==RHASH(i,i+mid-1))l=mid;
			else r=mid-1;
		}
		pa[i]=l;
	}
	for(int i=1;i<=n;i++)f[i][0]=pa[i];
	int k=log2(n);
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)if(i+(1<<j)-1<=n)f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++)if(l[i])
	{
		int L=l[i]+(n-i+1),R=i-1;
		if(L>R)continue;
		int l=1,r=(R-L+2)/2;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(query(L+mid-1,R-mid+1)>=mid)l=mid;
			else r=mid-1;
		}
		if(2*l-1+(n-i+1)*2>ans)ans=2*l-1+(n-i+1)*2,num=i,len=l;
	}
	bool flag=false;
	int ps;
	for(int i=1;i<=n;i++)if(pa[i]*2-1>ans)ans=pa[i]*2-1,flag=true,ps=i;
	if(flag)
	{
		puts("1");
		write(ps-pa[ps]+1),PC(' '),write(pa[ps]*2-1),puts("");
		return 0;
	}
	puts("3");
	write(l[num]),PC(' '),write(n-num+1),puts("");
	for(int i=l[num]+n-num+1;i<num;i++)if(pa[i]>=len&&i-len+1>l[num]+n-num&&i+len-1<num)pos=i;
	write(pos-len+1),PC(' '),write(2*len-1),puts("");
	write(num),PC(' '),write(n-num+1),puts("");
	return 0;
}