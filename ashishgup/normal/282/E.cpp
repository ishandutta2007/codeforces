#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int a[N], pref[N], suf[N];

typedef struct data
{
	data* bit[2];
	int cnt=0;
}trie;

trie* head;

void insert(int x)
{
	trie* node = head;
	for(int i=40;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		if(node->bit[curbit]==NULL)
		{
			node->bit[curbit]=new trie();
		}  
		node=node->bit[curbit];
		node->cnt++;
	}
}

void remove(int x)
{
	trie* node = head;
	for(int i=40;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		node=node->bit[curbit];
		node->cnt--;
	}
}

int maxxor(int x)
{
	trie* node = head;
	int ans=0;
	for(int i=40;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		if(node->bit[curbit^1]!=NULL && node->bit[curbit^1]->cnt>0)
		{
			ans+=(1LL<<i);
			node=node->bit[curbit^1];
		}
		else
			node=node->bit[curbit];
	}
	return ans;
}

int32_t main()
{
	IOS;
	head=new trie();
	insert(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]^a[i];
		insert(pref[i]);
	}
	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]^a[i];
	int ans=maxxor(0);
	for(int i=n;i>=1;i--)
	{
		remove(pref[i]);
		ans=max(ans, maxxor(suf[i]));
	}
	cout<<ans;
	return 0;
}