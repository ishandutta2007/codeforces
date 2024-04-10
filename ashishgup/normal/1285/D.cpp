#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
  
typedef struct data
{
	data* bit[2];
	int cnt = 0;
}trie;

trie* head;

void insert(int x)
{
	trie* cur = head;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		if(!cur->bit[b])
			cur->bit[b] = new trie();
		cur = cur->bit[b];
		cur->cnt++;
	}
}

int rec(trie *cur, int b)
{
	if(cur == NULL)
		return -1e18;
	if(b < 0)
		return 0;
	int val1 = rec(cur -> bit[0], b - 1);
	int val2 = rec(cur -> bit[1], b - 1);
	int x = max((1LL << b) + val1 , val2);
	int y = max(val1, (1LL << b) + val2);
	return min(x, y);
}


int n;
int a[N], cnt[50];

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
	int ans = rec(head, 30);
	cout << ans;
	return 0;
}