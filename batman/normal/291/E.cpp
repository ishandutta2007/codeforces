// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((301*1000))
#define INF ((ll)1e9)

ll n,f[N],f2[N][26],ans;
string s;
vector <pair<ll,string> > e[N];

void dfs(ll x,ll p=0)
{
	ll p2=p;
	for(int i=0;i<e[x].size();i++)
	{
		string t=e[x][i].second;
		bool flg=1;
		p=p2;
		for(int j=0;j<t.size();j++)
		{
			//cout<<j<<" "<<p<<" "<<f2[p+1][t[j]-'a']<<"\n";
			p=f2[p+1][t[j]-'a'];
			if(p==(ll)s.size())ans++,p=f[p];
		}
		if(flg)dfs(e[x][i].first,p);
	}
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		ll v;
		string t;
		cin>>v>>t;
		e[v].push_back({i,t});
	}
	cin>>s;
	for(int i=1,j=0;i<s.size();i++)
	{
		while(s[i]!=s[j] && j)j=f[j];
		if(s[i]==s[j])j++;
		f[i+1]=j;
	}
	for(int i=0;i<s.size();i++)
		for(int j=0;j<26;j++)
		{
			if(s[i]-'a'==j)f2[i+1][j]=i+1;
			else f2[i+1][j]=f2[f[i]+1][j];
		}
	dfs(1);
	cout<<ans;
	return 0;
}