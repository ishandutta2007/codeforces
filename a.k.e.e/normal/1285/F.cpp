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
const int MAXN=100005;

int m;
bool a[MAXN],notp[MAXN];
vector<int> d[MAXN];
int cnt[MAXN],prm[MAXN],pn,mu[MAXN];
int sta[MAXN],top;
void euler()
{
	notp[1]=1;mu[1]=1;
	for(int i=2;i<=m;++i)
	{
		if(!notp[i])prm[++pn]=i,mu[i]=-1;
		for(int j=1;j<=pn && i*prm[j]<=m;++j)
		{
			notp[i*prm[j]]=1;
			if(!(i%prm[j])){mu[i*prm[j]]=0;break;}
			mu[i*prm[j]]=-mu[i];
		}
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int N,x;
	readint(N);
	while(N--)readint(x),chkmax(m,x),a[x]=1;
	for(int i=1;i<=m;++i)
		for(int j=i;j<=m;j+=i)
			d[j].pb(i);
	euler();
	ll ans=m;
	for(int i=m;i;--i)
	{
		for(int j=m/i;j;--j)
		{
			if(!a[j*i])continue;
			int sum=0;
			for(auto k:d[j])sum+=cnt[k]*mu[k],++cnt[k];
			for(;sum;--top)
			{
				int x=sta[top];
				if(__gcd(x,j)==1)chkmax(ans,1ll*x*j*i),--sum;
//if(__gcd(x,j)==1 && i==1)cerr<<x<<" "<<j<<endl;
				for(auto k:d[x])--cnt[k];
			}
			sta[++top]=j;
		}
		for(;top;--top)
			for(auto k:d[sta[top]])
				--cnt[k];
	}
	printf("%lld\n",ans);
	return 0;
}