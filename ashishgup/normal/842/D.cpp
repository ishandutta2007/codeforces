#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, m;
int a[N];

typedef struct data
{
	data* bit[2];
	int cnt = 0, contains = 0;
}trie;

trie* head;

void insert(trie* cur, int x, int i)
{
	cur->cnt++;
	if(i < 0)
	{
		cur->contains = 1;
		return;
	}
	int curbit = x>>i & 1;
	if(!cur->bit[curbit])
		cur->bit[curbit] = new trie();
	insert(cur->bit[curbit], x, i-1);
	cur->contains = 0;
	if(cur->bit[0])
		cur->contains += cur->bit[0]->contains;
	if(cur->bit[1])
		cur->contains += cur->bit[1]->contains;
}

int query(trie* cur, int x, int i)
{
	if(!cur || i<0)
		return 0;
	int curbit = x>>i & 1;
	if(cur->bit[curbit] && cur->bit[curbit]->contains == (1<<i))
		return (1<<i) | query(cur->bit[!curbit], x, i-1);
	else
		return query(cur->bit[curbit], x, i-1);
}

int32_t main()
{
	IOS;
	head = new trie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		insert(head, a[i], 20);
	}
	int x = 0;
	while(m--)
	{
		int cur;
		cin>>cur;
		x ^= cur;
		int ans = query(head, x, 20);
		cout<<ans<<endl;
	}
	return 0;
}