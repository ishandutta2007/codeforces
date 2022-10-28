#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int taken[N], sieve[N];
vector<int> fact[N], ans[N];

typedef struct data
{
	data* bit[2];
	int store[2]={INT_MAX, INT_MAX};
	int cnt=0;
}trie;

trie* head[N];

void insert(int idx, int x)
{
	trie* node=head[idx];
	for(int i=30;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(node->bit[1]==NULL)
			{
				node->bit[1]=new trie();
			}
			node->store[1]=min(node->store[1], x);
			node=node->bit[1];
		}
		else
		{
			if(node->bit[0]==NULL)
			{
				node->bit[0]=new trie();
			}
			node->store[0]=min(node->store[0], x);
			node=node->bit[0];
		}
		node->cnt++;
	}
}

int maxxor(int idx, int x, int lim)
{
	int ans=0;
	trie* node=head[idx];
	for(int i=30;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(node->bit[0]!=NULL && node->bit[0]->cnt!=0 && node->store[0]<=lim)
			{
				ans+=(1LL<<i);
				node=node->bit[0];
			}
			else if(node->bit[1]!=NULL && node->bit[1]->cnt!=0 && node->store[1]<=lim)
			{
				node=node->bit[1];
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if(node->bit[1]!=NULL && node->bit[1]->cnt!=0 && node->store[1]<=lim)
			{
				ans+=(1LL<<i);
				node=node->bit[1];
			}
			else if(node->bit[0]!=NULL && node->bit[0]->cnt!=0 && node->store[0]<=lim)
			{
				node=node->bit[0];
			}
			else
			{
				return -1;
			}
		}
	}
	return ans;
}


void precompute()
{
	for(int i=1;i<N;i++)
	{
		for(int j=1;i*j<N;j++)
		{
			fact[i*j].push_back(i);
		}
	}
}

int32_t main()
{
	IOS;
	precompute();
	for(int i=1;i<N;i++)
		head[i]=new trie();
	int q;
	cin>>q;
	while(q--)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int u;
			cin>>u;
			if(!taken[u])
			{
				taken[u]=1;
				for(auto it:fact[u])
				{
					insert(it, u);
				}
			}
		}
		else
		{
			int x, k, s;
			cin>>x>>k>>s;
			if(x%k!=0)
			{
				cout<<"-1"<<endl;
			}
			else
			{
				int maxv=s-x;
				int ans=maxxor(k, x, maxv);
				if(ans!=-1)
					ans^=x;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}