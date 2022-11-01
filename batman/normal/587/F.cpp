#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define SQ ((ll)300)

int n,q,ver[N];
ll ans[N];
int nex[N][26],f[N],_cnt=1;
string s[N];
vector <pair<int,pair<int,int> > > big_qu[N];
vector <pair<int,int> > small_qu[N];
vector <int> e[N];
int cnt[N];
ll prt[N];
int strt[N],fnsh[N];
int a[N],lazy[N];

void add(int l,int r)
{
	while(l<r && l%SQ)a[l]++,l++;
	while(l<r && r%SQ)r--,a[r]++;
	for(int i=l/SQ;i<r/SQ;i++)lazy[i]++;
}

int query(int x){return a[x]+lazy[x/SQ];}

void build()
{
	for(int i=0;i<n;i++)
	{
		int now=0;
		for(int j=0;j<s[i].size();j++)
		{
			if(!nex[now][s[i][j]-'a'])nex[now][s[i][j]-'a']=_cnt++;
			now=nex[now][s[i][j]-'a'];
		}
		ver[i]=now;		
	}
	queue <int> qu;
	for(int i=0;i<26;i++)
		if(nex[0][i])
			qu.push(nex[0][i]);
	while(qu.size())
	{
		int x=qu.front();qu.pop();
		e[f[x]].push_back(x);
		for(int i=0;i<26;i++)
		{
			if(!nex[x][i]){nex[x][i]=nex[f[x]][i];continue;}
			f[nex[x][i]]=nex[f[x]][i];
			qu.push(nex[x][i]);
		}
	}
}

void pre_dfs(int x)
{
	strt[x]=_cnt++;
	for(auto u:e[x])
		pre_dfs(u);
	fnsh[x]=_cnt;
}

void dfs_cnt(int x)
{
	for(auto u:e[x])
		dfs_cnt(u),
		cnt[x]+=cnt[u];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s[i];
	build();
	for(int i=1;i<=q;i++)
	{
		int l,r,k;
		cin>>l>>r>>k;l--;r--;k--;
		if(s[k].size()>=SQ)big_qu[k].push_back({i,{l,r}});
		else
		{
			small_qu[r].push_back({i,k});
			if(l)small_qu[l-1].push_back({-i,k});
		}
	}
	_cnt=0;
	pre_dfs(0);
	for(int i=0;i<n;i++)
	{
		add(strt[ver[i]],fnsh[ver[i]]);
		if(s[i].size()>=SQ)
		{
			memset(cnt,0,sizeof cnt);
			int now=0;
			for(int j=0;j<s[i].size();j++)
			{
				now=nex[now][s[i][j]-'a'];
				cnt[now]++;
			}
			dfs_cnt(0);
			for(int i=0;i<n;i++)prt[i]=(i?prt[i-1]:0)+cnt[ver[i]];
			for(auto u:big_qu[i])ans[u.first]=prt[u.second.second]-(u.second.first?prt[u.second.first-1]:0);
		}
		for(auto u:small_qu[i])
		{
			ll res=0;
			int now=0;
			for(int j=0;j<s[u.second].size();j++)
			{
				now=nex[now][s[u.second][j]-'a'];
				res+=query(strt[now]);
			}
			if(u.first<0)res=-res;
			ans[abs(u.first)]+=res;
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}