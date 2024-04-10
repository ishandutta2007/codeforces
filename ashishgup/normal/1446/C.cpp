#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

typedef struct data
{
	data* bit[2];
	int cnt=0;
}trie;
 
trie* head;
 
void insert(int x)
{
	trie* node = head;
	for(int i=30;i>=0;i--)
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
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		node=node->bit[curbit];
		node->cnt--;
	}
}
 
int minxor(int x)
{
	trie* node = head;
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		if(node->bit[curbit]!=NULL && node->bit[curbit]->cnt>0)
			node=node->bit[curbit];
		else
		{
			ans+=(1LL<<i);
			node=node->bit[curbit^1];
		}
	}
	return ans;
}

int dp(trie* cur)
{
	if(cur -> cnt == 1)
		return cur -> cnt;
	if(cur -> bit[0] == NULL)
		return dp(cur -> bit[1]);
	else if(cur -> bit[1] == NULL)
		return dp(cur -> bit[0]);
	else
		return 1 + max(dp(cur -> bit[0]), dp(cur -> bit[1]));
}
 
int n, sz;
int a[N];

int32_t main()
{
	IOS;
	head = new trie();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		insert(a[i]);
	}
	cout << n - dp(head);
	return 0;
}