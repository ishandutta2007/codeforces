#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
void readint(int &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
inline void chkmin(int &x,int y){x>y?x=y:0;}
inline void chkmax(int &x,int y){x<y?x=y:0;}
const int MAXN=300005,MAXK=19;

int n,a[MAXN];
int _log2[MAXN],rmq[MAXN][MAXK];
void init()
{
	_log2[1]=0;
	enum(i,2,3*n)_log2[i]=_log2[i-1]+(i>=(1<<(_log2[i-1]+1)));
	enum(i,1,3*n)rmq[i][0]=a[i];
	enum(j,1,MAXK-1)
		enum(i,1,3*n-(1<<j)+1)
			rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
inline int RMQ(int l,int r)
{
	int t=_log2[r-l+1];
	return max(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

int f[MAXN],res[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	memset(res,0x3f,sizeof(res));
	readint(n);
	enum(i,1,n)
	{
		readint(a[i]);
		a[2*n+i]=a[n+i]=a[i];
	}
	init();
	enum(i,1,3*n)
	{
		int L=1,R=i,ans=0,mid;
		while(L<=R)
		{
			mid=(L+R)>>1;
			if(RMQ(mid,i)>2*a[i])ans=mid,L=mid+1;
			else R=mid-1;
		}
		f[i]=ans;
		chkmin(res[f[i]],i-1);
//cerr<<f[i]<<" ";
	}
//cerr<<endl;
	try(i,3*n,1)
		chkmin(res[i],res[i+1]);
	enum(i,1,n)
		printf("%d ",res[i]==0x3f3f3f3f?-1:(res[i]-i+1));
	return 0;
}