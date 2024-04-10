//Similar idea: https://codeforces.com/blog/entry/47100

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

int store1[50], store2[50];

typedef struct trie
{
	typedef struct node
	{
		node* nxt[2];
		int cnt = 0;

		node()
		{
			nxt[0] = nxt[1] = NULL;
			cnt = 0;
		}

	}Node;

	Node* head;

	trie() { head = new Node(); }

	void insert(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			cur -> cnt++;
			int b = (x >> i) & 1;
			if(b && (cur -> nxt[0] != NULL))
				store1[i] += cur -> nxt[0] -> cnt;
			else if(!b && (cur -> nxt[1]))
				store2[i] += cur -> nxt[1] -> cnt;
			if(!cur -> nxt[b])
				cur -> nxt[b] = new Node();
			cur = cur -> nxt[b];
		}
		cur -> cnt++;
	}

	void remove(int x)
	{
		Node* cur = head;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			cur = cur -> nxt[b];
			cur -> cnt--;
		}
	}

	int maxxor(int x)
	{
		Node* cur = head;
		int ans = 0;
		for(int i = 30; i >= 0; i--)
		{
			int b = (x >> i) & 1;
			if(cur -> nxt[!b] && cur -> nxt[!b] -> cnt > 0)
			{
				ans += (1LL << i);
				cur = cur -> nxt[!b];
			}
			else
				cur = cur -> nxt[b];
		}
		return ans;
	}
}Trie;

int n;
int a[N];


int32_t main()
{
	IOS;
	Trie t;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		t.insert(a[i]);
	}
	int inv = 0, x = 0;
	for(int b = 30; b >= 0; b--)
	{
		inv += min(store1[b], store2[b]);
		if(store2[b] > store1[b])
			x += (1LL << b);
	}
	cout << inv << " " << x;
	return 0;
}