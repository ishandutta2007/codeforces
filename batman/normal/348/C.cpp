#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define SQ ((ll)320)
#define QS ((ll)N/SQ+10)
#define INF ((ll)1e9)

int n,m,q,id[N],id2[QS],num_sq,common[N][QS];
vector <int> v[N];

ll a[N],base_big[QS],add_from_small[QS],add[QS];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<m;i++)
	{
		int k;
		cin>>k;
		if(k>SQ)id[i]=num_sq,id2[num_sq]=i;
		for(int j=0;j<k;j++)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
			if(k>SQ)base_big[num_sq]+=a[x];
		}
		sort(v[i].begin(),v[i].end());
		if(k>SQ)num_sq++;
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<num_sq;j++)
		{
			for(auto u:v[i])
			{
				int pos=lower_bound(v[id2[j]].begin(),v[id2[j]].end(),u)-v[id2[j]].begin();
				if(pos!=v[id2[j]].size() && v[id2[j]][pos]==u)common[i][j]++;
			}
		}
	while(q--)
	{
		char c;
		int x,val;
		cin>>c>>x;x--;
		if(c=='?')
		{
			if(v[x].size()>SQ)
			{
				ll res=base_big[id[x]]+add_from_small[id[x]];
				for(int i=0;i<num_sq;i++)res+=add[i]*common[x][i];
				cout<<res<<"\n";
			}
			else
			{
				ll res=0;
				for(auto u:v[x])res+=a[u];
				for(int i=0;i<num_sq;i++)res+=add[i]*common[x][i];
				cout<<res<<"\n";
			}
		}
		else
		{
			cin>>val;
			if(v[x].size()>SQ)
				add[id[x]]+=val;
			else
			{
				for(auto u:v[x])a[u]+=val;
				for(int i=0;i<num_sq;i++)add_from_small[i]+=val*common[x][i];
			}
		}
	}
    return 0;
}