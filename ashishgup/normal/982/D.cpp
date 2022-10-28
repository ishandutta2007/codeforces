#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int b[N], vis[N];
pair<int, int> a[N];
int connected;
int root[N], sz[N];
map<int, int> store;

void init()
{
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		sz[i]=1;
	}
	connected=0;
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];
		k=root[k];
	}
	return k;
}

void merge(int u, int v)
{
	int rt1=rt(u);
	int rt2=rt(v);

	if(rt1==rt2)
		return;

	connected--;

	store[sz[rt1]]--;
	store[sz[rt2]]--;
	store[sz[rt1]+sz[rt2]]++;

	if(store[sz[rt1]]==0)
	{
		store.erase(sz[rt1]);
	}

	if(store[sz[rt2]]==0)
	{
		store.erase(sz[rt2]);
	}

	if(sz[rt2]>=sz[rt1])
	{	
		sz[rt2]+=sz[rt1];
		sz[rt1]=0;
		root[rt1]=root[rt2];
	}
	else
	{
		sz[rt1]+=sz[rt2];
		sz[rt2]=0;
		root[rt2]=root[rt1];
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
		b[i]=a[i].first;
	}
	sort(a+1, a+n+1);
	int ans=0, finans=0;
	for(int i=1;i<=n;i++)
	{
		connected++;
		store[1]++;
		int idx=a[i].second;
		vis[idx]=1;
		if(vis[idx-1])
		{
			merge(idx, idx-1);
		}
		if(vis[idx+1])
		{			
			merge(idx, idx+1);
		}
		if(store.size()==1)
		{
			if(connected>ans)
			{
				ans=connected;
				finans=a[i].first+1;
			}
		}
	}
	cout<<finans;
	return 0;
}