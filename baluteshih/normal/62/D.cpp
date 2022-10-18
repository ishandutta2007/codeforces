#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<int> ans,out,input;
set<pii> G[105];
pii arr[2005];
bitset<2005> vis;
const int INF=1e9;

void dfs(int u,int bi)
{
	while(true)
	{
		auto p=G[u].lower_bound(MP(bi,INF));
		while(p!=G[u].end()&&vis[p->S])
			p=G[u].erase(p);
		if(p==G[u].end())
			return ans.pb(u),void();
		auto tmp=*p;
		G[u].erase(p),vis[tmp.S]=1,dfs(tmp.F,0),bi=0;
	}
}

int main()
{jizz
	int n,m,st,ls,x;
	cin >> n >> m >> ls,st=ls,input.pb(st);
	for(int i=0;i<m;++i)
		cin >> x,arr[i]=MP(ls,x),ls=x,input.pb(x);
	for(int i=m-1;i>=0;--i)
	{
		int lss=arr[i].S-1;
		while(true)
		{
			vis.reset(),ans.clear();
			for(int j=1;j<=n;++j)
				G[j].clear();
			for(int j=m-1;j>=i;--j)
				G[arr[j].F].insert(MP(arr[j].S,j)),G[arr[j].S].insert(MP(arr[j].F,j));
			auto t=G[arr[i].F].lower_bound(MP(lss,INF));
			if(t!=G[arr[i].F].end()) dfs(arr[i].F,t->F),lss=t->F;
			else break;
			if(ans.size()+i==m+1&&ans[0]==st)
			{
				out.clear();
				for(int j=0;j<i;++j)
					out.pb(arr[j].F);
				reverse(ALL(ans));
				for(int j=0;j<ans.size();++j)
					out.pb(ans[j]);
				if(out>input)
				{
					for(int j=0;j<out.size();++j)
						cout << out[j] << " \n"[j+1==out.size()];
					return 0;
				}
			}
		}
	}
	cout << "No solution\n";
}