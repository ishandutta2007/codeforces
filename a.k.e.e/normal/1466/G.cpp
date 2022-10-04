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
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=100005,MAXK=1000005;

int n,m,k;
char a[105],b[MAXN],c[MAXK];
int cnt[MAXN][26],pw[MAXN];
bool no[105];
int solve(string s,int l,int r)
{
	if(l>r)return 0;
	if(s.length()==1)return dmy(cnt[r][s[0]-'a']-1ll*cnt[l-1][s[0]-'a']*pw[r-l+1]%MOD+MOD);
	int res=0;
	for(int t=0;t<=1;++t)
	{
		bool flag=1;
		for(int i=t;i<s.length();i+=2)if(s[i]!=b[l]){flag=0;break;}
		if(flag)
		{
			string ss="";
			for(int i=(t^1);i<s.length();i+=2)ss.pb(s[i]);
			inc(res,solve(ss,l+1,r));
		}
	}
	return res;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,id;
	readint(m),readint(Q);
	scanf("%s%s",a,b+1);n=strlen(a);
	pw[0]=1;
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<26;++j)
			cnt[i][j]=dmy(cnt[i-1][j]*2+('a'+j==b[i]));
		pw[i]=dmy(pw[i-1]<<1);
	}
	while(Q--)
	{
		readint(id);
		scanf("%s",c);k=strlen(c);
		memset(no,0,sizeof(no));
		for(int i=n+1;i<k;++i)if(c[i]!=c[i-n-1])no[i%(n+1)]=1;
		int sum=0;
		for(int i=0;i<=n;++i)if(no[i])++sum;
		int res=0;
		for(int i=0;i<=n;++i)
		{
			if(sum!=(no[(i+n)%(n+1)]?1:0))continue;
			bool flag=0;
			for(int j=0;j<n;++j)
				if((i+j)%(n+1)<k && c[(i+j)%(n+1)]!=a[j])
					{flag=1;break;}
			if(flag)continue;
			int v=(i+n)%(n+1);
			string s="";
			for(int w=v;w<k;w+=n+1)s.pb(c[w]);
			if(s.empty())inc(res,pw[id]);
			else inc(res,solve(s,1,id));
		}
		printf("%d\n",res);
	}
	return 0;
}