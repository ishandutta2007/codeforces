#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

typedef struct data
{
	data* bit[2];
	int cnt=0;
}trie;

int n, k, ans=0;
int a[N], pref[N];
trie* head;

void insert(int x)
{
	trie* node = head;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		if(node->bit[curbit]==NULL)
			node->bit[curbit]=new trie();
		node=node->bit[curbit];
		node->cnt++;
	}
}

int query(int x)
{
	trie* node = head;
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		if((k>>i)&1)
		{
			if(node->bit[curbit^1]!=NULL)
				node=node->bit[curbit^1];
			else
				return ans;
		}
		else
		{
			if(node->bit[curbit^1]!=NULL)
				ans+=node->bit[curbit^1]->cnt;
			if(node->bit[curbit]!=NULL)
				node=node->bit[curbit];
			else
				return ans;
		}
	}
	ans+=node->cnt;
	return ans;
}

int32_t main()
{
	IOS;
	head = new trie();
	insert(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]^a[i];
		ans+=query(pref[i]);
		insert(pref[i]);
	}
	cout<<ans;
	return 0;
}