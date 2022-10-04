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
const int MAXN=300005,MAXK=19;

int n;
ll a[MAXN],pre[MAXN],ps[MAXN];
int pp[MAXN];
ll rmq[2][MAXN][MAXK];
int _log2[MAXN];
vector<int> v[MAXN];
ll qmin(int w,int l,int r)
{
	int t=_log2[r-l+1];
	return min(rmq[w][l][t],rmq[w][r-(1<<t)+1][t]);
}
int qnum(int l,int r,ll c)
{
	int i=lower_bound(ps+1,ps+n+1,c)-ps;
	if(i>n || ps[i]!=c)return 0;
	return lower_bound(v[i].begin(),v[i].end(),r+1)-lower_bound(v[i].begin(),v[i].end(),l);
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=n;++i)ps[i]=pre[i]=pre[i-1]+((i&1)?-a[i]:a[i]),v[i].clear();
	sort(ps+1,ps+n+1);
	for(int i=1;i<=n;++i)
	{
		pp[i]=lower_bound(ps+1,ps+n+1,pre[i])-ps;
		v[pp[i]].pb(i);
	}
	_log2[1]=0;for(int i=2;i<=n;++i)_log2[i]=_log2[i>>1]+1;
	for(int i=1;i<=n;++i)
		rmq[i&1][i][0]=((i&1)?-pre[i]:pre[i]),
		rmq[(i&1)^1][i][0]=1ll<<60;
	for(int w=0;w<2;++w)
		for(int j=1;j<MAXK;++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
				rmq[w][i][j]=min(rmq[w][i][j-1],rmq[w][i+(1<<j-1)][j-1]);
	ll res=0;
	for(int i=1;i<=n;++i)
	{
		int L=i,R=n,mid,ans=i-1;
		while(L<=R)
		{
			mid=(L+R)>>1;
			if(qmin(1,i,mid)>=-pre[i-1] && qmin(0,i,mid)>=pre[i-1])L=mid+1,ans=mid;
			else R=mid-1;
		}
		res+=qnum(i,ans,pre[i-1]);
	}
	printf("%lld\n",res);
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