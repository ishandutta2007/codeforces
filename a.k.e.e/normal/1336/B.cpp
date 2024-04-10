#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=100005;

int n[3],a[3][MAXN];
ll s(int x){return 1ll*x*x;}
ll work(int x,int y,int z){/*cerr<<x<<" "<<y<<" "<<z<<endl;*/return s(x-y)+s(y-z)+s(z-x);}
void solve()
{
	ll res=1ll<<62;
	for(int k=0;k<3;++k)readint(n[k]);
	for(int k=0;k<3;++k)
	{
		for(int i=1;i<=n[k];++i)readint(a[k][i]);
		a[k][n[k]+1]=0;
		sort(a[k]+1,a[k]+n[k]+1);
	}
	for(int x=0;x<3;++x)
	{
		int y=(x+1)%3,z=(x+2)%3;
		for(int i=1;i<=n[x];++i)
		{
			int uy=lower_bound(a[y]+1,a[y]+n[y]+1,a[x][i])-a[y],
				uz=lower_bound(a[z]+1,a[z]+n[z]+1,a[x][i])-a[z];
			int vy=a[y][uy-1],vz=a[z][uz-1];
			uy=a[y][uy],uz=a[z][uz];
			int ux=a[x][i];
			if(uy && uz)chkmin(res,work(ux,uy,uz));
			if(vz && uy)chkmin(res,work(ux,uy,vz));
			if(vy && uz)chkmin(res,work(ux,vy,uz));
			if(vy && vz)chkmin(res,work(ux,vy,vz));
		}
	}
	printf("%lld\n",res);
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