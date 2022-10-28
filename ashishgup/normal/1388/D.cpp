#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, ans = 0;
int a[N], b[N];
vector<int> g[N];
vector<int> v, order;

bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 1; i <= n; i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(int i = 1; i <= n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}

int store[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		store[i] = a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
		if(b[i] != -1)
			g[i].push_back(b[i]);
	}
	toposort(n);
	vector<int> st, ed;
	for(auto &it:order)
	{
		ans += a[it];
		if(a[it] >= 0)
		{
			a[b[it]] += a[it];
			st.push_back(it);
		}
		else
			ed.push_back(it);
	}
	cout << ans << endl;
	int sum = 0;
	for(auto &it:st)
	{
		sum += store[it];
		if(b[it] != -1)
			store[b[it]] += store[it];
		cout << it << " ";
	}
	reverse(ed.begin(), ed.end());
	for(auto &it:ed)
	{
		sum += store[it];
		if(b[it] != -1)
			store[b[it]] += store[it];
		cout << it << " ";
	}
	assert(sum == ans);
	cout << endl;
	return 0;
}