#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=205,m=52;

int n,o;
char str[MAXN];
int len[MAXN],a[MAXN][MAXN];
pii b[MAXN][m+3];
pii perm[(m+3)<<10],from[m+3][1<<10];
int dp[m+3][1<<10];
int calval(pii p)
{
	int res=0;
	for(int i=0;i<n;++i)
		if(p.y&(1<<i))res+=b[i][p.x].y;
		else res+=b[i][p.x].x;
	return res;
}
void solve()
{
	memset(b,0,sizeof(b));
	memset(dp,-0x3f,sizeof(dp));
	readint(n);
	for(int i=0;i<n;++i)
	{
		scanf("%s",str+1);len[i]=strlen(str+1);
		for(int j=1;j<=len[i];++j)
		{
			int c=a[i][j]=(isupper(str[j])?str[j]-'A'+26:str[j]-'a');
			if(!b[i][c].x)b[i][c].x=j;
			else b[i][c].y=j;
		}
	}
	o=0;
	for(int c=0;c<m;++c)
	{
		int s=0;
		for(int i=0;i<n;++i)
		{
			if(!b[i][c].x){s=-1;break;}
			if(b[i][c].y)s^=(1<<i);
		}
		if(s<0)continue;
		for(int t=0;t<(1<<n);++t)
			if((t&s)==t)perm[++o]=mp(c,t);
	}
	sort(perm+1,perm+o+1,[&](pii p,pii q){return calval(p)<calval(q);});
	int res=0;pii fin=mp(-1,-1);
	for(int ii=1;ii<=o;++ii)
	{
		int c=perm[ii].x,s=perm[ii].y;
		if(chkmax(dp[c][s],1))from[c][s]=mp(-1,-1);
		for(int t=0;t<s;++t)
			if((t&s)==t)
			{
				if(chkmax(dp[c][s],dp[c][t]))
					from[c][s]=from[c][t];
			}
//cerr<<c<<' '<<s<<' '<<dp[c][s]<<endl;
		for(int d=0;d<m;++d)
		{
			int t=0;
			for(int i=0;i<n;++i)
			{
				int pos=(s&(1<<i))?b[i][c].y:b[i][c].x;
//if(c==0 && d==2)cerr<<"           "<<pos<<' '<<b[i][d].x<<' '<<b[i][d].y<<endl;
				if(!b[i][d].x || (!b[i][d].y && b[i][d].x<=pos) || (b[i][d].y && b[i][d].y<=pos))
					{t=-1;break;}
				if(b[i][d].x<=pos)t^=(1<<i);
			}
//if(t>=0)cerr<<d<<' '<<t<<endl;
			if(t>=0 && chkmax(dp[d][t],dp[c][s]+1))
				from[d][t]=mp(c,s);
		}
		if(chkmax(res,dp[c][s]))fin=mp(c,s);
	}
	
	printf("%d\n",res);
	vector<int> opt;
	for(pii p=fin;p.x>=0;p=from[p.x][p.y])opt.pb(p.x);
	reverse(opt.begin(),opt.end());
	for(auto i:opt)putchar(i<26?i+'a':i-26+'A');
	putchar('\n');
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}