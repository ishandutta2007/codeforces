#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5;
vector<int> ve[N],gg[N];
struct re{
	int a,b;
};
vector<re> Q[N];
int ans[N],ch[N];
void dfs(int x,int y)
{
	int now=0;
	for (auto v:ve[x])
	  if (v!=y)
	  {
	     ch[x]++;
	  	 dfs(v,x);
	  	 now=max(now,(int)(gg[v].size()));
	  }
	gg[x].resize(now+1);
	for(auto v:ve[x])
	  if (v!=y)
	  {
	  	 for(int j=0;j<gg[v].size();j++) gg[x][j]+=max(0,gg[v][j]-j-1);
	  }
	int j=0; 
	for (j=0;j<gg[x].size();j++) gg[x][j]+=ch[x];
/*	if (x==1)
	{
		for (auto v:gg[7]) cerr<<v<<" ";
		cout<<endl;
		for (auto v:gg[x]) cerr<<v<<" ";
		cout<<endl;
    }*/
    for(auto v:Q[x])
	{
		if (v.a>=gg[x].size()) ans[v.b]=ch[x];
		else ans[v.b]=gg[x][v.a];
	}
    while (!gg[x].empty()&&gg[x].back()-((int)(gg[x].size())-1)<=1) gg[x].pop_back();
	while (ch[x]-(int)(gg[x].size())>1) gg[x].push_back(ch[x]);

}
int main()
{
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n;
	rep(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	cin>>q;
	rep(i,1,q)
	{
		int x,y;
		cin>>x>>y;
		Q[x].push_back((re){y,i});
	}
	dfs(1,0);
//	cerr<<gg[1].size()<<" "<<gg[1][2]<<endl;
	rep(i,1,q) cout<<ans[i]<<"\n";
	return 0;
}