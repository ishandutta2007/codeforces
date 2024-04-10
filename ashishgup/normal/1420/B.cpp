#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
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
			int b = (x >> i) & 1;
			if(!cur -> nxt[b])
				cur -> nxt[b] = new Node();
			cur = cur -> nxt[b];
			cur -> cnt++;
		}
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

	int get(Node* cur)
	{
		if(cur == NULL)
			return 0;
		if(cur -> nxt[1] == NULL)
			return get(cur -> nxt[0]);
		if(cur -> nxt[0] == NULL)
			return 0;
		return cur -> nxt[1] -> cnt * cur -> nxt[0] -> cnt + get(cur -> nxt[0]);
	}
}Trie;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		Trie cur;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			cur.insert(a[i]);
		}
		int ans = n * (n - 1) / 2;
		ans -= cur.get(cur.head);
		cout << ans << endl;
	}
	return 0;
}