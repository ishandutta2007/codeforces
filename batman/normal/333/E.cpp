#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)3010)


int n,x[N],y[N];
vector <pair<int,pair<int,int> > > ed;
bitset <N> b[N],ex;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int dis=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			ed.push_back({dis,{i,j}});
		}
	sort(ed.begin(),ed.end());
	for(int i=(ll)ed.size()-1;i>=0;i--)
	{
		int v=ed[i].second.first,u=ed[i].second.second;
		ex=(b[v]&b[u]);
		if(ex._Find_first()!=ex.size())return cout<<fixed<<setprecision(16)<<(ld)sqrt((ld)ed[i].first)/2,0;
		b[v][u]=b[u][v]=1;
	}
	return 0;
}