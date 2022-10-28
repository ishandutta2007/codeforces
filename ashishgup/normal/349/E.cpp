#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int block=sqrt(N)+5;

int n, m, q, sz=0; //sz = Number of heavy sets
int a[N], sum[N], heavy[N], rheavy[block];
int have[N], toGive[N];
int tims[N][block];
vector<int> s[N], contains[N];

int get(int idx)
{
	if(heavy[idx])
	{
		int ans=sum[idx] + have[idx] + toGive[idx]*s[idx].size();
		return ans;
	}
	else
	{
		int ans=0;
		for(auto &it:s[idx])
			ans+=a[it];
		for(int i=1;i<=sz;i++)
			ans+=tims[idx][i]*toGive[rheavy[i]];
		return ans;
	}
}

void update(int idx, int x)
{
	if(heavy[idx])
		toGive[idx]+=x;
	else
	{
		for(auto &it:s[idx])
			a[it]+=x;
	}
	for(int i=1;i<=sz;i++)
		have[rheavy[i]]+=tims[idx][i]*x;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int idx;
			cin>>idx;
			s[i].push_back(idx);
			sum[i]+=a[idx];
			contains[idx].push_back(i);
		}
		if(k>=block)
			heavy[i]=++sz, rheavy[sz]=i;
	}
	for(int i=1;i<=sz;i++)
	{
		for(auto &idx:s[rheavy[i]])
		{
			for(auto &other:contains[idx])
			{
				if(other!=rheavy[i])
					tims[other][i]++;
			}	
		}
	}
	while(q--)
	{
		char op;
		cin>>op;
		if(op=='?')
		{
			int k;
			cin>>k;
			cout<<get(k)<<endl;
		}
		else
		{
			int k, x;
			cin>>k>>x;
			update(k, x);
		}
	}
	return 0;
}