#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
#define mp make_pair
#define pb push_back
#define x first
#define y second
template <typename TYPE> inline void chkmin(TYPE &a,TYPE b){b<a?a=b:0;}
template <typename TYPE> inline void chkmax(TYPE &a,TYPE b){a<b?a=b:0;}
template <typename TYPE> inline void readint(TYPE &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=1005,M=1000;

int n;
char s[MAXN];
int a[MAXN],b[MAXN];
int cur[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);scanf("%s",s+1);
	enum(i,1,n)readint(a[i]),readint(b[i]);
	enum(i,1,n)
	{
		cur[i][0]=s[i]-'0';
		enum(j,1,M)
			if(j>=b[i] && !((j-b[i])%a[i]))
				cur[i][j]=cur[i][j-1]^1;
			else cur[i][j]=cur[i][j-1];
	}
	int ans=0;
	enum(j,0,M)
	{
		int cnt=0;
		enum(i,1,n)cnt+=cur[i][j];
		chkmax(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}