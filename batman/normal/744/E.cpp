#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)35)
#define M ((ll)201*1000)
#define B ((ll)31)
#define MOD ((ll)1e9+9)

int n,strt[N],mark[M];
ll tvn[M];
string s[N];
vector <ll> hsh[N];
vector <pair<int,int> > e[M];

bool dfs(int x,int l,int r)
{
	mark[x]=1;
	for(auto u:e[x])
		if((u.first==0 || (l<=u.first && u.first<r)) && (u.second==-1 || (l<=u.second && u.second<r)))
			if(mark[u.first]==1 || (!mark[u.first] && dfs(u.first,l,r)))
				return 1;
	mark[x]=2;
	return 0;
}

bool check(int l,int r)
{
	memset(mark,0,sizeof mark);
	l=strt[l];r=strt[r+1];
	for(int i=l;i<r;i++)
		if(!mark[i] && dfs(i,l,r))
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	tvn[0]=1;for(int i=1;i<M;i++)tvn[i]=(tvn[i-1]*B)%MOD;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		strt[i+1]=strt[i]+(int)s[i].size();
		hsh[i].push_back(s[i][0]-'a'+2);
		for(int j=1;j<s[i].size();j++)
			hsh[i].push_back((hsh[i].back()*B+(s[i][j]-'a'+2))%MOD);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<s[i].size();j++)
		{
			int len=(int)s[i].size()-j;
			for(int k=0;k<n;k++)
			{
				if(s[k].size()==j && hsh[k].back()==hsh[i][j-1])
					e[0].push_back({strt[i]+j,strt[k]});
				if(s[k].size()>=len)
				{
					ll h1=(hsh[i][j-1]*tvn[len])%MOD;
					h1=(((hsh[i].back()-h1)%MOD)+MOD)%MOD;
					if(h1==hsh[k][len-1])
					{
						if(s[k].size()>len)
							e[strt[i]+j].push_back({strt[k]+len,-1});
						else
							e[strt[i]+j].push_back({0,strt[k]});
					}
					continue;
				}
				ll h1=(hsh[i][j-1]*tvn[s[k].size()])%MOD;
				h1=(((hsh[i][j+(int)s[k].size()-1]-h1)%MOD)+MOD)%MOD;
				if(h1==hsh[k].back())
					e[strt[i]+j].push_back({strt[i]+j+(int)s[k].size(),strt[k]});
			}
		}
	}
	int ans=0;
	for(int i=0,j=0;i<n;i++)
	{
		if(j<i)j=i;
		while(j<n && check(i,j))j++;
		ans+=j-i;
	}
	cout<<ans<<"\n";
    return 0;
}