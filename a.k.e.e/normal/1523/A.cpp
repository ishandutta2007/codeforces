#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
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
const int MAXN=1005;

int n,m;
char a[MAXN];
vector<int> b;
int res[MAXN];
void solve()
{
	readint(n),readint(m);
	scanf("%s",a+1);
	b.clear();
	for(int i=1;i<=n;++i)if(a[i]=='1')b.pb(i);
	memset(res,0,sizeof(res));
	for(int j=1;j<b.size();++j)
	{
		int l=b[j-1],r=b[j];
		if(r-l-1>=2*m)
		{
			for(int k=l;k<=l+m;++k)res[k]=1;
			for(int k=r-m;k<=r;++k)res[k]=1;
		}
		else
		{
			for(int k=l;k<=r;++k)res[k]=1;
			if((r-l-1)&1)res[(l+r)/2]=0;
		}
	}
	if(!b.empty())
	{
		for(int i=0;i<=m && (b[0]-i>0 || b.back()+i<=n);++i)
		{
			if(b[0]>i)res[b[0]-i]=1;
			if(b.back()+i<=n)res[b.back()+i]=1;
		}
	}
	for(int i=1;i<=n;++i)putchar(res[i]+'0');
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