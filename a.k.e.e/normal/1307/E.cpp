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
const int MAXN=5005,MOD=1000000007;

int n,E,a[MAXN];
vector<pii> v[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int best=0,sum=0,x,y;
	readint(n),readint(E);
	for(int i=1;i<=n;++i)readint(a[i]);
	while(E--)
	{
		readint(x),readint(y);
		pii p(0,0);
		for(int i=1,j=y;i<=n;++i)
		{
			if(a[i]==x)--j;
			if(!j){p.x=i;break;}
		}
		if(!p.x)continue;
		for(int i=n,j=y;i;--i)
		{
			if(a[i]==x)--j;
			if(!j){p.y=i;break;}
		}
		v[x].pb(mp(p.x,p.y));
	}
/*for(int i=1;i<=n;++i)
{
	cerr<<i<<":";
	for(auto p:v[i])
		cerr<<"("<<p.x<<","<<p.y<<")";
	cerr<<endl;
}*/
	for(int i=0;i<=n;++i)
	{
		int col=0;
		for(int j=1;j<=n;++j)
		{
			for(auto p:v[j])
				if(p.x==i){col=j;break;}
			if(col)break;
		}
		if(i && !col)continue;
		int res=0,way=1;
		for(int j=1;j<=n;++j)
		{
			if(v[j].empty())continue;
			if(j==col)
			{
				int c=0;
				for(auto p:v[j])
					if(p.y>i && p.x!=i)++c;
				if(c)res+=2,way=1ll*way*c%MOD;
				else ++res;
				continue;
			}
			int lc=0,rc=0,add=0;
			for(auto p:v[j])
			{
				if(p.x<i)++lc;
				if(p.y>i)++rc;
				if(p.x<i && p.y>i)++add;
			}
			if(lc*rc>add)res+=2,way=(1ll*lc*rc-add)%MOD*way%MOD;
			else if(lc || rc)
			{
				++res;
				way=1ll*way*(lc+rc)%MOD;
			}
		}
		if(res>best)best=res,sum=way;
		else if(res==best)sum=(sum+way)%MOD;
	}
	printf("%d %d\n",best,sum);
	return 0;
}