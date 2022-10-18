#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

priority_queue<pii,vector<pii>,greater<pii>> pq;
int deg[200001],ans[200001];
pii edge[200001];
vector<pii> child[200001];
bitset<200001> out;

int main()
{jizz
	int n,m,k,a,b,cnt;
	cin >> n >> m >> k,cnt=n;
	for(int i=1;i<=m;++i)
		cin >> a >> b,child[a].pb(MP(b,i)),child[b].pb(MP(a,i)),++deg[a],++deg[b],edge[i]=MP(a,b);
	for(int i=1;i<=n;++i)
		pq.push(MP(deg[i],i));
	for(int i=m;i>=1;--i)
	{
		while(!pq.empty() && pq.top().F<k)
		{
			auto t=pq.top();
			pq.pop();
			if(out[t.S]) continue;
			//cout << t.F << " " << t.S << "\n";
			out[t.S]=1,--cnt;
			for(auto j:child[t.S])
				if(!out[j.F] && j.S<=i) --deg[j.F],pq.push(MP(deg[j.F],j.F));
		}
		ans[i]=cnt;
		if(!out[edge[i].F] && !out[edge[i].S]) 
			--deg[edge[i].F],--deg[edge[i].S],pq.push(MP(deg[edge[i].F],edge[i].F)),pq.push(MP(deg[edge[i].S],edge[i].S));
	}
	for(int i=1;i<=m;++i)
		cout << ans[i] << "\n";
}