#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
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
const int MAXN=400005,MAXK=19,INF=1<<30;

int n;
char a[MAXN];
int b[MAXN],_log2[MAXN],rmq[MAXN][MAXK];
int lch[MAXN],rch[MAXN];
ll fin[MAXN],ans[MAXN];
void init()
{
	_log2[1]=0;
	for(int i=2;i<=n;++i)_log2[i]=_log2[i>>1]+1;
	for(int i=1;i<=n;++i)rmq[i][0]=i;
	for(int j=1;j<MAXK;++j)
		for(int i=1;i<=n-(1<<j)+1;++i)
			if(b[rmq[i][j-1]]<=b[rmq[i+(1<<(j-1))][j-1]])rmq[i][j]=rmq[i][j-1];
			else rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
}
inline int RMQ(int l,int r)
{
	int t=_log2[r-l+1];
	return b[rmq[l][t]]<=b[rmq[r-(1<<t)+1][t]]?rmq[l][t]:rmq[r-(1<<t)+1][t];
}
int work(int l,int r)
{
	if(l==r)
	{
		fin[l]=1;
		return l;
	}
	int mid=RMQ(l,r);
	lch[mid]=work(l,mid-1),rch[mid]=work(mid+1,r);
	if(a[mid]=='S')fin[mid]=min(fin[lch[mid]],fin[rch[mid]]);
	else fin[mid]=fin[lch[mid]]+fin[rch[mid]];
	return mid;
}
void dfs(int id,ll gv)
{
	if(!lch[id]){ans[id]=gv;return;}
	if(a[id]=='S')
	{
		if(fin[lch[id]]==fin[id])dfs(lch[id],gv);
		else dfs(rch[id],gv);
	}
	else
	{
		gv=gv/fin[id];
		dfs(lch[id],gv*fin[lch[id]]);
		dfs(rch[id],gv*fin[rch[id]]);
	}
}
void solve()
{
	int r;
	readint(r);
	int cur=0;
	n=0;
	for(char c=getchar();c!='\n';c=getchar())
	{
		if(c==' ')continue;
		if(c=='(')++cur;
		else if(c==')')--cur;
		else
		{
			++n;
			a[n]=c;
			if(c!='*')b[n]=cur;
			else b[n]=INF;
			ans[n]=fin[n]=lch[n]=rch[n]=0;
		}
	}
	init();
	int rt=work(1,n);
	dfs(rt,fin[rt]*fin[rt]*r);
	printf("REVOLTING ");
	for(int i=1;i<=n;++i)
		if(a[i]=='*')printf("%I64d ",ans[i]);
	putchar('\n');
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}