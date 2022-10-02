#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int U[200005],V[200005],a[500005],W[200005];
int fa[400005],n,m;
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
inline void add(int u,int v,int w)
{
	if(w) fa[ff(u)]=ff(v+n);
	if(w) fa[ff(u+n)]=ff(v);
	if(!w) fa[ff(u)]=ff(v);
	if(!w) fa[ff(u+n)]=ff(v+n);
}
inline int cnt(int x)
{
	int rtn=0;
	while(x) rtn+=x&1,x>>=1;
	return rtn; 
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i=1;i<=n*2+2;i++) fa[i]=i,a[i]=-1;
		for(int i=1;i<n;i++)
		{
			cin >> U[i] >> V[i];
			int w;
			cin >> w;
			W[i]=w;
			if(w>=0) add(U[i],V[i],cnt(w)&1);
		}
		for(int i=1;i<=m;i++)
		{
			int x,y,w;
			cin >> x >> y >> w;
			if(w>=0) add(x,y,w);
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(ff(i)==ff(i+n)) flag=0;
		}
		if(flag)
		{
			cout << "YES\n";
			for(int i=1;i<=n;i++)
			{
				int x=ff(i);
				if(a[x]==-1)
				{
					if(x>n) a[x-n]=1,a[x]=0;
					else a[x]=1,a[x+n]=0;
				}
				if(x>n) a[i]=a[x],a[i+n]=a[x]^1;
				else a[i]=a[x],a[i+n]=a[x]^1;
			}
			for(int i=1;i<n;i++)
			{
				cout << U[i] << " " << V[i] << " ";
				if(W[i]==-1) cout << (a[U[i]]^a[V[i]]) << "\n";
				else cout << W[i] << "\n";
			}
		}
		else cout << "NO\n";
	}
	return 0;
}