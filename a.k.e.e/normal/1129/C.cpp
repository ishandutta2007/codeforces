#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=3005,MAXK=15,MOD=1000000007;

int n,d[MAXN];
inline bool calc(int l,int r)
{
	int t=r-l+1;
	if(t<=3)return 1;
	if(t>=5)return 0;
	int ans=0;
	for(int i=l;i<=r;i++)
		ans=(ans<<1|d[i]);
	return ans!=3 && ans!=5 && ans!=14 && ans!=15;
}

struct Suffix
{
	int x,y,id;
	Suffix(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
	inline bool operator ==(const Suffix &b)const {return x==b.x && y==b.y;}
}wa[MAXN],wb[MAXN];
int wcnt[MAXN],sa[MAXN],rk[MAXN],height[MAXN];
void buildsa()
{
	d[0]=-1;
	Suffix *a=wa,*b=wb;
	int tot=0,k=1;
	for(int i=1;i<=n;i++)wcnt[d[i]]++;
	wcnt[1]+=wcnt[0];
	for(int i=n;i>0;i--)sa[wcnt[d[i]]--]=i;
	for(int i=1;i<=n;i++)
		if(d[sa[i]]==d[sa[i-1]])rk[sa[i]]=tot;
		else rk[sa[i]]=++tot;
	while(k<=n)
	{
		for(int i=1;i<=n;i++)a[i]=Suffix(rk[i],i+k>n?0:rk[i+k],i);
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=n;i++)wcnt[a[i].y]++;
		for(int i=1;i<=n;i++)wcnt[i]+=wcnt[i-1];
		for(int i=n;i>0;i--)b[wcnt[a[i].y]--]=a[i];
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=n;i++)wcnt[b[i].x]++;
		for(int i=1;i<=n;i++)wcnt[i]+=wcnt[i-1];
		for(int i=n;i>0;i--)a[wcnt[b[i].x]--]=b[i];
		tot=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[i-1])rk[a[i].id]=tot;
			else rk[a[i].id]=++tot;
		if(tot==n)break;
		k<<=1;
	}
	for(int i=1;i<=n;i++)sa[rk[i]]=i;
	k=0;
	for(int i=1;i<=n;i++)
	{
		if(k)k--;
		for(int t=sa[rk[i]-1];i+k<=n && t+k<=n && d[i+k]==d[t+k];k++);
		height[rk[i]]=k;
	}
}
int _log2[MAXN],rmq[MAXN][MAXK];
void getst()
{
	_log2[1]=0;
	for(int i=2;i<=n;i++)
		_log2[i]=_log2[i-1]+((1<<(_log2[i-1]+1))==i);
	for(int i=1;i<=n;i++)rmq[i][0]=height[i];
	for(int j=1;j<MAXK;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
inline int lcp(int x,int y)
{
	x=rk[x];y=rk[y];
	if(x>y)swap(x,y);++x;
	int t=_log2[y-x+1];
	return min(rmq[x][t],rmq[y-(1<<t)+1][t]);
}
int nxt[MAXN],pre[MAXN][MAXN],f[MAXN][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&d[i]);
    buildsa();
    getst();
	for(int i=1;i<=n;i++)
	{
		int pos=0;
		for(int j=1;j<i;j++)
			if(i+lcp(i,j)-1>nxt[i])
			{
				nxt[i]=max(nxt[i],i+lcp(i,j)-1);
				pos=j;
			}
		for(int k=i;k<=nxt[i];k++)
			pre[i][k]=pos;
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i-1]=1;
		for(int j=i;j<=n;j++)
			if(!pre[i][j])
			{
				for(int k=max(j-3,i);k<=j;k++)
					if(calc(k,j))f[i][j]=(f[i][j]+f[i][k-1])%MOD;
			}
			else f[i][j]=f[pre[i][j]][pre[i][j]+j-i];
	}
	/*for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			cout<<i<<" "<<j<<" "<<pre[i][j]<<" "<<calc(i,j)<<" "<<f[i][j]<<" "<<endl;*/
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			if(!pre[j][i])ans=(ans+f[j][i])%MOD;
		printf("%d\n",ans);
	}
    return 0;
}