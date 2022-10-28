#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 2105;
 
typedef struct data
{
	data* nxt[26];
	pair<int, int> p;
}trie;
 
trie* head;
int dp[N], nxt[N];
pair<int, int> store[N];
 
void insert(string &s, int idx)
{
	for(int i = 0; i < s.size(); i++)
	{
		trie* cur = head;
		for(int j = i; j < s.size(); j++)
		{
			int ch = s[j] - 'a';
			if(!cur->nxt[ch])
				cur->nxt[ch] = new trie();
			cur = cur->nxt[ch];
			cur -> p = {j, idx};
		}
	}
}
 
string s, t;
 
void go(int idx)
{
	int i = idx;
	trie* cur = head;
	while(idx < t.size())
	{
		int ch = t[idx] - 'a';
		if(!cur -> nxt[ch])
			return;
		cur = cur -> nxt[ch];
		idx++;
		if(1 + dp[idx] < dp[i])
		{
			dp[i] = 1 + dp[idx];
			nxt[i] = idx;
			store[i] = cur -> p;
		}
	}
}
 
int32_t main()
{
	IOS;
	head = new trie();
	for(int i = 0; i < N; i++)
		dp[i] = 2e9;
	cin >> s >> t;
	dp[t.size()] = 0;
	store[t.size()] = {-1, -1};
	insert(s, 0);
	string str = s;
	reverse(str.begin(), str.end());
	insert(str, 1);
	for(int i = t.size() - 1; i >= 0; i--)
		go(i);
	if(dp[0] > 1e5)
	{
		cout << -1;
		return 0;
	}
	cout << dp[0] << endl;
	int i = 0, prv = -1;
	while(i < t.size())
	{
		int nx = nxt[i];
		int len = nxt[i] - i;
		pair<int, int> p = store[i];
		if(p.second == 0)
			cout << p.first - len + 2 << " " << p.first + 1 << endl;
		else
		{
			int idx = s.size() - p.first;
			cout << idx + len - 1 << " " << idx << endl; 
		}
		i = nx;
	}
	return 0;
}