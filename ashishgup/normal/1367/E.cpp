#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2005;

int n, k;
string s;
bool vis[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		map<char, int> f;
		for(auto &it:s)
			f[it]++;
		priority_queue<int> pq;
		for(auto &it:f)
			pq.push(it.second);
		for(int len = n; len >= 1; len--)
		{
			priority_queue<int> cur = pq;
			for(int idx = 0; idx < n; idx++)
				vis[idx] = 0;
			int flag = 1;
			for(int idx = 0; idx < len; idx++)
			{
				if(vis[idx])
					continue;
				int ct = 0, i = idx;
				while(!vis[i])
				{
					ct++;
					vis[i] = 1;
					i = (i + k) % len;
				}
				if(cur.top() < ct)
				{
					flag = 0;
					break;
				}
				int val = cur.top();
				val -= ct;
				cur.pop();
				cur.push(val);
			}
			if(flag)
			{
				cout << len << endl;
				break;
			}
		}
	}
	return 0;
}