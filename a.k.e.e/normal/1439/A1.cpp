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
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=105;

int n,m;
char str[MAXN];
int a[MAXN][MAXN];
struct Data
{
	int x0,y0,x1,y1,x2,y2;
	Data(int x0,int y0,int x1,int y1,int x2,int y2):x0(x0),y0(y0),x1(x1),y1(y1),x2(x2),y2(y2){}
};
vector<Data> res;
void work(int x0,int y0,int x1,int y1,int x2,int y2)
{
	res.pb(Data(x0,y0,x1,y1,x2,y2));
	a[x0][y0]^=1,a[x1][y1]^=1,a[x2][y2]^=1;
}
pii pr[5];
void cal(int a,int b,int c)
{
	work(pr[a].x,pr[a].y,pr[b].x,pr[b].y,pr[c].x,pr[c].y);
}
void solve()
{
	res.clear();
	readint(n),readint(m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;++j)a[i][j]=str[j]-'0';
	}
	for(int i=n;i>=3;--i)
	{
		for(int j=m;j>=3;--j)
			if(a[i][j])work(i,j,i-1,j,i,j-1);
		if(a[i][2] && a[i][1])work(i,2,i-1,2,i,1);
		else if(a[i][2])work(i,2,i-1,2,i-1,1);
		else if(a[i][1])work(i,1,i-1,2,i-1,1);
	}
	for(int j=m;j>=3;--j)
		if(a[2][j] && a[1][j])work(2,j,1,j,2,j-1);
		else if(a[2][j])work(2,j,1,j-1,2,j-1);
		else if(a[1][j])work(1,j,1,j-1,2,j-1);
	int cnt=0;
	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j)
			if(a[i][j])pr[++cnt]=mp(i,j);
	int tcc=cnt;
	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j)
			if(!a[i][j])pr[++tcc]=mp(i,j);
	if(cnt==4)cal(1,2,3),cal(1,2,4),cal(1,3,4),cal(2,3,4);
	else if(cnt==3)cal(1,2,3);
	else if(cnt==2)cal(1,3,4),cal(2,3,4);
	else if(cnt==1)cal(1,2,3),cal(1,2,4),cal(1,3,4);
	printf("%d\n",res.size());
	for(auto p:res)printf("%d %d %d %d %d %d\n",p.x0,p.y0,p.x1,p.y1,p.x2,p.y2);
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