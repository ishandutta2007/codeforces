#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

struct data
{
	int sum = -1e9, cnt;
	int a = -1, b = -1, c = -1;

	data() 
	{
		sum = -1e9, cnt = 0, a = -1, b = -1, c = -1;
	}

	bool operator >(const data &other)
	{
		return sum > other.sum;
	}
};

int n;
data out;
vector<int> g[N];

data merge(data a, data b)
{
	data ans;
	ans.cnt = a.cnt + b.cnt;
	ans.sum = a.sum + b.sum;
	vector<int> v;
	if(a.a != -1)
		v.push_back(a.a);
	if(a.b != -1)
		v.push_back(a.b);
	if(a.c != -1)
		v.push_back(a.c);
	if(b.a != -1)
		v.push_back(b.a);
	if(b.b != -1)
		v.push_back(b.b);
	if(b.c != -1)
		v.push_back(b.c);
	if(ans.cnt >= 1)
		ans.a = v[0];
	if(ans.cnt >= 2)
		ans.b = v[1];
	if(ans.cnt >= 3)
		ans.c = v[2];
	return ans;
}

vector<data> dfs(int u, int par) //{, 1 leaf (Farthest)} {, 2 leaves}, {, 3 leaves}
{
	data p1, p2, p3;
	p1.cnt = 1, p2.cnt = 2, p3.cnt = 3;
	p1.sum = 0;
	p1.a = u;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		vector<data> v = dfs(it, u);
		data cp1 = v[0];
		data cp2 = v[1];
		data cp3 = v[2];
		data np1 = p1, np2 = p2, np3 = p3;
		if(cp1 > p1)
			np1 = cp1;
		if(cp2 > p2)
			np2 = cp2;
		{
			data cur = merge(p1, cp1);
			if(cur > np2)
				np2 = cur;
		}
		{
			data cur = merge(p1, cp2);
			if(cur > np3)
				np3 = cur;
		}
		{
			data cur = merge(p2, cp1);
			if(cur > np3)
				np3 = cur;
		}
		p1 = np1;
		p2 = np2;
		p3 = np3;
	}
	if(p1.sum == -1e9)
		p1.sum = 0;
	if(p3 > out)
		out = p3;
	p1.sum++;
	p2.sum++;
	p3.sum++;
	vector<data> temp = {p1, p2, p3};
	return temp;
}

int32_t main()
{
	IOS;
	out = data();
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = 0;
	for(int i = 1; i <= n; i++)
	{
		if(g[i].size() > 1)
		{
			root = i;
			break;
		}
	}
	dfs(root, root);
	cout << out.sum << endl;
	cout << out.a << " " << out.b << " " << out.c;
	return 0;
}