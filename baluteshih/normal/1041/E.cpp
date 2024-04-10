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

vector<int> edge[1005];
pii ans[1005];
set<int> eQQ;

int main()
{jizz
	int n,a,b;
	cin >> n;
	for(int i=1;i<n;++i)
	{
		cin >> a >> b;
		if(b!=n)
			return cout << "NO\n",0;
		edge[a].pb(i);
	}
	for(int i=n-1;i>0;--i)
		if(edge[i].empty()) eQQ.insert(i);
	for(int i=n-1,l;i>=0;--i)
	{
		l=n;
		for(auto x:edge[i])
			if(x==edge[i].back()) ans[x]=MP(l,i);
			else 
			{
				auto p=eQQ.lower_bound(i);
				if(p==eQQ.begin())
					return cout << "NO\n",0;
				else --p,ans[x]=MP(l,*p),l=*p,eQQ.erase(p);
			}
	}
	cout << "YES\n";
	for(int i=1;i<n;++i)
		cout << ans[i].F << " " << ans[i].S << "\n";
}