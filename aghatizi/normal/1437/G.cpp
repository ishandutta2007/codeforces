#include<bits/stdc++.h>
using namespace::std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int maxs = 27;

bool fn[maxn];

int nxt[maxn][maxs] , ind[maxn] , f[maxn] , id = 1;

string s[maxn];

vector<int> adj[maxn];

int addTrie(string tmp)
{
	int pos = 0;
	for(int ch : tmp)
	{
		ch -= 'a';
		if(!nxt[pos][ch])
			nxt[pos][ch] = id++;

		pos = nxt[pos][ch];
	}

	fn[pos] = 1;
	return pos;
}

void aho()
{
	queue<int> q;
	for(int i = 0; i < maxs; i++)
		if(nxt[0][i])
			q.push(nxt[0][i]);

	while(!q.empty())
	{
		int v = q.front();
		q.pop();

		for(int i = 0; i < maxs; i++)
		{
			if(nxt[v][i])
			{
				f[nxt[v][i]] = nxt[f[v]][i];
				q.push(nxt[v][i]);
			}
			else
				nxt[v][i] = nxt[f[v]][i];
		}
	}
}

int st[maxn] , ft[maxn] , now = -1 , sus[maxn];

void plant(int v , int p = -1)
{
	st[v] = ++now;

	for(auto u : adj[v])
		plant(u , v);

	ft[v] = now + 1;
}


multiset<int> seg[maxn * 4];

int get(int p , int s = 0 , int e = id , int v = 1)
{
	int val = -1;
	if(!seg[v].empty())
		val = *seg[v].rbegin();

	if(e - s < 2)
		return val;

	int m = (s + e) / 2;
	
	if(p < m)
		val = max(val , get(p , s , m , 2 * v));
	else
		val = max(val , get(p , m , e , 2 * v + 1));

	return val;
}

void add(int l , int r , int val , int s = 0 , int e = id , int v = 1)
{
	if(l <= s && e <= r)
	{
		seg[v].insert(val);
		return;
	}

	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;
	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);
}

void rem(int l , int r , int val , int s = 0 , int e = id , int v = 1)
{
	if(l <= s && e <= r)
	{
		seg[v].erase(seg[v].find(val));
		return;
	}

	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;
	rem(l , r , val , s , m , 2 * v);
	rem(l , r , val , m , e , 2 * v + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , q;
	cin >> n >> q;

	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		ind[i] = addTrie(s[i]);
	}

	aho();

	for(int i = 1; i < id; i++)
		adj[f[i]].pb(i);

	plant(0);

	for(int i = 0; i < n; i++)
		add(st[ind[i]] , ft[ind[i]] , sus[i]);

	while(q--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int indx , x;
			cin >> indx >> x;
			indx--;

			rem(st[ind[indx]] , ft[ind[indx]] , sus[indx]);
			sus[indx] = x;
			add(st[ind[indx]] , ft[ind[indx]] , sus[indx]);
		}
		else
		{
			string t;
			cin >> t;

			int pos = 0 , res = -1;
			for(int ch : t)
			{
				pos = nxt[pos][ch - 'a'];
				res = max(res , get(st[pos]));
			}

			cout << res << endl;
		}
	}
}