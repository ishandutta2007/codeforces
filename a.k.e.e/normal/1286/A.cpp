#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
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
const int MAXN=105;

int n,a[MAXN],cnt[2];
vector<int> f[2];
int work(int x,int y)
{
	f[0].clear(),f[1].clear();
	a[0]=x,a[n+1]=y;
	cnt[0]=n/2,cnt[1]=n-n/2;
	for(int i=1;i<=n;++i)	
		if(a[i]>=0)cnt[a[i]]--;
	int las=0,ans=0;
	for(int i=1;i<=n+1;++i)
	{
		if(a[i]==-1)continue;
		if(a[i]==a[las])f[a[i]].pb(i-las-1);
		else ++ans;
		las=i;
	}
	for(int i=0;i<=1;++i)
	{
		sort(f[i].begin(),f[i].end());
		for(auto t:f[i])
			if(cnt[i]>=t)cnt[i]-=t;
			else ans+=2;
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		readint(a[i]);
		if(!a[i])a[i]=-1;
		else a[i]&=1;
	}
	int res=1<<30;
	for(int x=0;x<=1;++x)
		for(int y=0;y<=1;++y)
			chkmin(res,work(x,y));
	cout<<res<<endl;
	return 0;
}