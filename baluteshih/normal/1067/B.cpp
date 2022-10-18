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

queue<int> q;
vector<int> child[100001];
int lay[100001],cnt[100001];

int main()
{jizz
	int n,k,a,b,flag,cc=0;
	cin >> n >> k;
	for(int i=1;i<n;++i)
		cin >> a >> b,child[a].pb(b),child[b].pb(a);
	for(int i=1;i<=n;++i)
		if(child[i].size()==1)
			q.push(i),lay[i]=1,cnt[i]=3;
	while(!q.empty())
	{
		a=q.front(),q.pop();
		if(cnt[a]<3)
			return cout << "No\n",0;
		flag=0;
		for(int i:child[a])
			if(!lay[i])
			{
				++cnt[i],lay[i]=lay[a]+1,q.push(i),flag=1;
			}
			else 
			{
				if(lay[i]!=lay[a]+1&&lay[i]!=lay[a]-1)
					return cout << "No\n",0;
				if(lay[i]==lay[a]+1)
					++cnt[i],flag=1;
			}
		if(lay[a]==k+1) flag=1;
		if(!flag)
			return cout << "No\n",0;
	}
	for(int i=1;i<=n;++i)
		if(!lay[i])
			return cout << "No\n",0;
	for(int i=1;i<=n;++i)
		if(lay[i]==k+1) ++cc;
	if(*max_element(lay+1,lay+n+1)!=k+1||cc!=1) cout << "No\n";	
	else cout << "Yes\n";
}