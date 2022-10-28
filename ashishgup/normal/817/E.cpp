#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

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
			node->bit[curbit]=new trie();
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

int query(trie* node, int i, int x, int k)
{
	if(i==-1)
		return 0;
	int leftbit=(x>>i)&1;
	int rightbit=(k>>i)&1;
	int curans=0;
	if((1^leftbit)<rightbit && node->bit[1]!=NULL)
		curans+=node->bit[1]->cnt;
	if((1^leftbit)==rightbit && node->bit[1]!=NULL)
		curans+=query(node->bit[1], i-1, x, k);
	if((0^leftbit)<rightbit && node->bit[0]!=NULL)
		curans+=node->bit[0]->cnt;
	if((0^leftbit)==rightbit && node->bit[0]!=NULL)
		curans+=query(node->bit[0], i-1, x, k);
	return curans;
}

int32_t main()
{
	IOS;
	head=new trie();
	int q;
	cin>>q;
	while(q--)
	{
		int type, x;
		cin>>type>>x;
		if(type==1)
			insert(x);
		else if(type==2)
			remove(x);
		else
		{
			int k;
			cin>>k;
			cout<<query(head, 30, x, k)<<endl;
		}
	}
	return 0;
}