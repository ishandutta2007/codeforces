#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)2010)

ll n,ans[N];
string a[N],b[N];
bool mark[N];
vector <ll> e[N],er[N],topol;
ll topol_num[N],comp[N],cnt_comp;

void add_edge(ll x,ll y)
{
	e[x^1].push_back(y);e[y^1].push_back(x);
	er[y].push_back(x^1);er[x].push_back(y^1);
}

void dfs(ll x)
{
	mark[x]=1;
	for(auto u:e[x])
		if(!mark[u])
			dfs(u);
	topol.push_back(x);
	topol_num[x]=topol.size();
}

void dfs2(ll x)
{
	comp[x]=cnt_comp;
	for(auto u:er[x])
		if(!comp[u])
			dfs2(u);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s,t;
		cin>>s>>t;
		a[i]=s[0];a[i]+=s[1];a[i]+=s[2];
		b[i]=s[0];b[i]+=s[1];b[i]+=t[0];
		for(int j=0;j<i;j++)
		{
			if(a[i]==a[j])
				add_edge(2*i+1,2*j+1),add_edge(2*i,2*j+1),add_edge(2*i+1,2*j);
			if(a[i]==b[j])
				add_edge(2*i+1,2*j);
			if(b[i]==a[j])
				add_edge(2*i,2*j+1);
			if(b[i]==b[j])
				add_edge(2*i,2*j);
		}
	}
	cnt_comp=1;
	for(int i=0;i<2*n;i++)if(!mark[i])dfs(i);
	reverse(topol.begin(),topol.end());
	for(auto u:topol)if(!comp[u])dfs2(u),cnt_comp++;
	for(int i=0;i<n;i++)
	{
		if(comp[2*i]==comp[2*i+1])return cout<<"NO",0;
		if(comp[2*i+1]>comp[2*i])ans[i]=1;
		else ans[i]=0;
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)
	{
		if(ans[i]==0)cout<<a[i]<<"\n";
		else cout<<b[i]<<"\n";
	}
	return 0;
}