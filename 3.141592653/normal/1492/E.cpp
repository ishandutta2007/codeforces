#include<bits/stdc++.h>
// Basic typedefs 
typedef long long ll;
typedef double db;
typedef unsigned unt;
typedef unsigned long long ull;
// STL function usage
using std::min;
using std::max;
using std::swap;
using std::reverse;
using std::sort;
// STL container usage
using std::vector;
using std::set;
using std::multiset;
using std::map;
using std::deque;
using std::queue;
// Basic pair
struct pii
{
	int x,y;
	pii(){}
	pii(int xx,int yy){x=xx,y=yy;}
};
bool operator<(const pii x,const pii y)
{if(x.x^y.x)return x.x<y.x;return x.y<y.y;}
// Main

int n,m,k;
int a[1111111],c[1111111];
char s[1111111];
pii P[1111111];
std::vector<int>v[555555];
int comp(int x,int y)
{
	int ret=0;
	for(register int i=1;i<=m;i++)
		if(v[x][i]!=v[y][i])ret++;
	return ret;
}
int Ans[1111111];
void report()
{
	puts("Yes");
	for(register int i=1;i<=m;i++)
		printf("%d ",Ans[i]);
	puts("");
	exit(0);
}
void qfail()
{
	puts("No");
	exit(0);
}
int df[111],tp=0;
int MaxAllowDirty[1111111];
void checkans()
{
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		int mi=0;
		for(ii=1;ii<=tp;ii++)
			if(v[i][df[ii]]!=Ans[df[ii]])mi++;
		if(mi>MaxAllowDirty[i])return;
	}report();
}
void qwq3(int ZeroPos)
{
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		int mi=0;
		for(ii=1;ii<=tp;ii++)
			if(v[i][df[ii]]!=Ans[df[ii]])mi++;
		if(mi==MaxAllowDirty[i]+1)
		{
			Ans[ZeroPos]=v[i][ZeroPos];
			checkans();
			return;
		}if(mi>MaxAllowDirty[i])return;
	}Ans[ZeroPos]=1e9;
	checkans();
}
void solve3(int L,int R)
{
	register int i,ii;
	for(i=1;i<=m;i++)
		if(v[L][i]!=v[R][i])
			df[++tp]=i;
	for(i=1;i<=m;i++)
		if(i!=df[1]&&i!=df[2]&&i!=df[3]&&i!=df[4])Ans[i]=v[L][i];
	for(i=1;i<=n;i++)MaxAllowDirty[i]=2;
	for(i=2;i<=n;i++)
	{
		for(ii=1;ii<=m;ii++)
			if(ii!=df[1]&&ii!=df[2]&&ii!=df[3]&&ii!=df[4])
				if(v[i][ii]!=Ans[ii])
					MaxAllowDirty[i]--;
		if(MaxAllowDirty[i]<0)qfail();
	}
	Ans[df[1]]=v[L][df[1]],Ans[df[2]]=v[R][df[2]],Ans[df[3]]=0;
	qwq3(df[3]);
	Ans[df[1]]=v[R][df[1]],Ans[df[2]]=v[L][df[2]],Ans[df[3]]=0;
	qwq3(df[3]);
	Ans[df[2]]=v[L][df[2]],Ans[df[3]]=v[R][df[3]],Ans[df[1]]=0;
	qwq3(df[1]);
	Ans[df[2]]=v[R][df[2]],Ans[df[3]]=v[L][df[3]],Ans[df[1]]=0;
	qwq3(df[1]);
	Ans[df[3]]=v[L][df[3]],Ans[df[1]]=v[R][df[1]],Ans[df[2]]=0;
	qwq3(df[2]);
	Ans[df[3]]=v[R][df[3]],Ans[df[1]]=v[L][df[1]],Ans[df[2]]=0;
	qwq3(df[2]);
	qfail();
}
void solve4(int L,int R)
{
	register int i,ii;
	for(i=1;i<=m;i++)
		if(v[L][i]!=v[R][i])
			df[++tp]=i;
	for(i=1;i<=m;i++)
		if(i!=df[1]&&i!=df[2]&&i!=df[3]&&i!=df[4])Ans[i]=v[L][i];
	for(i=1;i<=n;i++)MaxAllowDirty[i]=2;
	for(i=2;i<=n;i++)
	{
		for(ii=1;ii<=m;ii++)
			if(ii!=df[1]&&ii!=df[2]&&ii!=df[3]&&ii!=df[4])
				if(v[i][ii]!=Ans[ii])
					MaxAllowDirty[i]--;
		if(MaxAllowDirty[i]<0)qfail();
	}
	Ans[df[1]]=v[L][df[1]];Ans[df[2]]=v[L][df[2]];
	Ans[df[3]]=v[R][df[3]];Ans[df[4]]=v[R][df[4]];
	checkans();
	Ans[df[1]]=v[L][df[1]];Ans[df[2]]=v[R][df[2]];
	Ans[df[3]]=v[R][df[3]];Ans[df[4]]=v[L][df[4]];
	checkans();
	Ans[df[1]]=v[L][df[1]];Ans[df[2]]=v[R][df[2]];
	Ans[df[3]]=v[L][df[3]];Ans[df[4]]=v[R][df[4]];
	checkans();
	Ans[df[1]]=v[R][df[1]];Ans[df[2]]=v[L][df[2]];
	Ans[df[3]]=v[R][df[3]];Ans[df[4]]=v[L][df[4]];
	checkans();
	Ans[df[1]]=v[R][df[1]];Ans[df[2]]=v[L][df[2]];
	Ans[df[3]]=v[L][df[3]];Ans[df[4]]=v[R][df[4]];
	checkans();
	Ans[df[1]]=v[R][df[1]];Ans[df[2]]=v[R][df[2]];
	Ans[df[3]]=v[L][df[3]];Ans[df[4]]=v[L][df[4]];
	checkans();
	qfail();
}
void exec()
{
	scanf("%d%d",&n,&m);
	register int i=1,ii;
	for(;i<=n;i++)
	{
		v[i].resize(m+2);
		for(ii=1;ii<=m;ii++)scanf("%d",&v[i][ii]);
	}
	int cmax=0,mxpos=-1;
	for(i=2;i<=n;i++)
	{
		int d=comp(1,i);
		if(d>4){puts("No");return;}
		if(d>cmax)cmax=d,mxpos=i;
	}
	if(cmax<=2)
	{
		puts("Yes");
		for(i=1;i<=m;i++)
			printf("%d ",v[1][i]);
		puts("");
		return;
	}
	if(cmax==3)return solve3(1,mxpos);
	return solve4(1,mxpos);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}