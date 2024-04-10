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
const int MAXN=65;

int n,m;
char s[MAXN][MAXN];
void solve()
{
	readint(n),readint(m);
	bool flag=0,fafa=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)
			if(s[i][j]=='A')flag=1;
			else fafa=1;
	}
	if(!flag){printf("MORTAL\n");return;}
	if(!fafa){printf("0\n");return;}
	int ans=4;
	for(int i=1;i<=n;++i)
	{
		if(s[i][1]=='A' || s[i][m]=='A')chkmin(ans,3-(i==1 || i==n));
		flag=1;
		for(int j=1;j<=m;++j)
			if(s[i][j]=='P')flag=0;
		if(flag)chkmin(ans,2-(i==1 || i==n));
	}
	for(int i=1;i<=m;++i)
	{
		if(s[1][i]=='A' || s[n][i]=='A')chkmin(ans,3-(i==1 || i==m));
		flag=1;
		for(int j=1;j<=n;++j)
			if(s[j][i]=='P')flag=0;
		if(flag)chkmin(ans,2-(i==1 || i==m));
	}
	printf("%d\n",ans);
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