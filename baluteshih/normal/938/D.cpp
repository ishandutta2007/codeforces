#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <bitset>
#include <queue>
#include <utility>
using namespace std;
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second

struct mode
{
	ll w,a;
	bool operator<(const mode&x)const{
		return w>x.w;
	}
};

vector<mode> child[200005];
ll wei[200005],in[200005],vis[2000005];
priority_queue<mode> q;

int main()
{jizz
	ll n,m,i,a,b,w;
	mode tmp;
	cin >> n >> m;
	while(m--)
		cin >> a >> b >> w,child[a].pb(mode{b,w}),child[b].pb(mode{a,w});
	for(i=1;i<=n;i++)
		cin >> wei[i],q.push(mode{wei[i],i});
	while(!q.empty())
	{
		tmp=q.top(),q.pop();
		if(vis[tmp.a]) continue;
		vis[tmp.a]=1;
		for(auto x:child[tmp.a])
		{
			if(vis[x.w]) continue;
			if(wei[x.w]>tmp.w+x.a*2)
			{
				wei[x.w]=tmp.w+x.a*2;
				q.push(mode{wei[x.w],x.w});
			}
		}
	}
	for(i=2,cout << wei[1];i<=n;i++)
		cout << " " << wei[i];
	cout << "\n";
}