#include <bits/stdc++.h>
using namespace std;
int fa[10005],sz[10005],qwq[1005];
inline int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
int cnt=0;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,d;
	cin >> n >> d;
	int cnt=1;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	while(d--)
	{
		int x,y;
		cin >> x >> y;
		if(ff(x)==ff(y)) ++cnt;
		else
		{
			sz[ff(x)]+=sz[ff(y)];
			sz[ff(y)]=0;
			fa[ff(y)]=ff(x);
		}
		for(int i=1;i<=n;i++) qwq[i]=sz[i];
		sort(qwq+1,qwq+n+1);
		reverse(qwq+1,qwq+n+1);
		int ans=0;
		for(int i=1;i<=cnt;i++)
			ans+=qwq[i];
		cout << ans-1 << "\n";
	}
	return 0;
}