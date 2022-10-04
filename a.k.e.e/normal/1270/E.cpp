#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1005;

int n,x[MAXN],y[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(x[i]),readint(y[i]);
	for(int i=2;i<=n;++i)x[i]-=x[1],y[i]-=y[1];
	x[1]=y[1]=0;
	while(1)
	{
		bool flag=1;
		for(int i=1;i<=n;++i)if((x[i]&1) || (y[i]&1))flag=0;
		if(!flag)break;
		for(int i=1;i<=n;++i)x[i]>>=1,y[i]>>=1;
	}
	int cnt=0;
	for(int i=1;i<=n;++i)if((x[i]+y[i])&1)++cnt;
	if(cnt<n && cnt>0)
	{
		printf("%d\n",cnt);
		for(int i=1;i<=n;++i)if((x[i]+y[i])&1)printf("%d ",i);
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;++i)if(x[i]&1)++cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i)if(x[i]&1)printf("%d ",i);
	return 0;
}