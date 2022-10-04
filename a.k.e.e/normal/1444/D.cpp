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
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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

int n,m,a[1005],b[1005];
bitset<250005> f[505];
int ra[1005],rb[1005];
vector<int> ca[2],cb[2];
bool work(int n,int *a,int *r)
{
	int s=0;
	for(int i=1;i<=n;++i)s+=a[i];
	if(s&1)return 0;
	s>>=1;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		f[i]=(f[i-1]<<a[i])|f[i-1];
	if(!f[n][s])return 0;
	for(int i=n;i;--i)
		if(s>=a[i] && f[i-1][s-a[i]])
			s-=a[i],r[i]=1;
	return 1;
}
void solve()
{
	readint(n);for(int i=1;i<=n;++i)readint(a[i]);
	readint(m);for(int i=1;i<=m;++i)readint(b[i]);
	if(n!=m){printf("No\n");return;}
	memset(ra,0,sizeof(ra));memset(rb,0,sizeof(rb));
	if(!work(n,a,ra) || !work(n,b,rb)){printf("No\n");return;}
	for(int t=0;t<=1;++t)ca[t].clear(),cb[t].clear();
	for(int i=1;i<=n;++i)ca[ra[i]].pb(a[i]),cb[rb[i]].pb(b[i]);
	for(int t=0;t<=1;++t)sort(ca[t].begin(),ca[t].end()),sort(cb[t].begin(),cb[t].end());
	printf("Yes\n");
	if(ca[0].size()<ca[1].size())swap(ca[0],ca[1]);
	if(cb[0].size()>cb[1].size())swap(cb[0],cb[1]);
int s=0;
for(auto x:cb[0])s+=x;
for(auto x:cb[1])s-=x;
assert(!s);
	int x=0,y=0;
	for(int i=0;i<cb[0].size();++i)
	{
		printf("%d %d\n",x,y+=cb[0][cb[0].size()-1-i]);
		printf("%d %d\n",x+=ca[0][i],y);
	}
	for(int i=cb[0].size();i<ca[0].size();++i)
	{
		printf("%d %d\n",x,y-=cb[1][ca[0].size()-1-i]);
		printf("%d %d\n",x+=ca[0][i],y);
	}
	for(int i=ca[0].size();i<n;++i)
	{
		printf("%d %d\n",x,y-=cb[1][n-1-i+ca[0].size()-cb[0].size()]);
		printf("%d %d\n",x-=ca[1][i-ca[0].size()],y);
	}
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