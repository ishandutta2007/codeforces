#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)
#define K ((ll)20)

char s[N];
int n,pos[K][N],a[N],rght[N],prt[N],cnt[2*N];
pair <pair<int,int>,int> tmp[N];
vector <pair<int,int> > v[N];

bool cmp(ll x,ll y){return pos[K-1][x]<pos[K-1][y];}

ll lcp(ll x,ll y)
{
	ll res=0;
	for(int i=K-1;x<n && y<n && i>=0;i--)
		if(pos[i][x]==pos[i][y])
			x+=(1<<i),y+=(1<<i),res+=(1<<i);
	return res;
}


int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	for(int i=0;i<n;i++)pos[0][i]=((s[i]=='(')?0:1),a[i]=i,prt[i]=(i?prt[i-1]:0)+((s[i]=='(')?1:-1);
	stack <ll> st;
	for(int i=n-1;i>=0;i--)
	{
		while(st.size() && prt[st.top()]>=prt[i])st.pop();
		rght[i+1]=n;
		if(st.size())rght[i+1]=st.top();
		st.push(i);
	}
	while(st.size() && prt[st.top()]>=0)st.pop();
	rght[0]=n;
	if(st.size())rght[0]=st.top();
	for(int i=1;i<K;i++)
	{
		for(int j=0;j<n;j++)
		{
			tmp[j]={{pos[i-1][j],-1},j};
			if(j+(1<<(i-1))<n)tmp[j].first.second=pos[i-1][j+(1<<(i-1))];
		}
		sort(tmp,tmp+n);
		for(int j=0,now=0;j<n;j++)
		{
			if(j && tmp[j].first!=tmp[j-1].first)now++;
			pos[i][tmp[j].second]=now;
		}
	}
	sort(a,a+n,cmp);
	v[a[0]].push_back({prt[a[0]]-1,1});
	v[rght[a[0]]].push_back({prt[a[0]]-1,-1});
	for(int i=1;i<n;i++)
	{
		int x=lcp(a[i-1],a[i]);
		if(a[i]+x>=rght[a[i]])continue;
		v[a[i]+x].push_back({prt[a[i]]-1,1});
		v[rght[a[i]]].push_back({prt[a[i]]-1,-1});
	}
	ll ans=0;
	for(int i=n-1;i>=0;i--)
	{
		cnt[N+prt[i]]++;
		for(auto u:v[i])
			ans+=u.second*cnt[N+u.first];
	}
	cout<<ans<<"\n";
	return 0;
}