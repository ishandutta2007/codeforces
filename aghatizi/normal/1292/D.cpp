#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e3 + 20;
const int maxN = 5e3;
const int maxm = maxn * 2;

vector<int> val[maxm] , adj[maxm];

int num[maxn] , shit[maxm];
bool is[maxn];

bool cmp(int a , int b)
{
	for(int i = 0; i < (int)val[a].size(); i++)
		if(val[a][i] != val[b][i])
			return val[a][i] < val[b][i];

	return 0;
}

bool is_par(int a , int b)
{
	bool found = 0;
	for(int i = 0; i < (int)val[a].size(); i++)
	{
		if(val[a][i] != val[b][i])
		{
			found = 1;
			if(val[a][i] > val[b][i])
				return 0;
		}
		else if(found && val[a][i] != 0)
			return 0;
	}

	return 1;
}

void prnt(vector<int> tmp)
{
	for(auto x : tmp)
		cout << x << " ";
	cout << endl;
}

int t[maxm] , n , Sz[maxm];

void dfs(int v)
{
	Sz[v] = t[v];
	for(auto u : adj[v])
	{
		dfs(u);
		Sz[v] += Sz[u];
	}
}

int getCent(int v)
{
	for(auto u : adj[v])
		if(Sz[u] * 2 > n)
			return getCent(u);
	
	return v;
}

int main()
{
	memset(num , -1 , sizeof num);

	int id = 0;
	for(int i = 2; i < maxn; i++)
		if(!is[i])
		{
			num[i] = id++;
			for(int j = 2 * i; j < maxn; j += i)
				is[j] = 1;
		}

	val[1].resize(id);
	for(int i = 2; i < maxn; i++)
	{
		val[i].resize(id);
		int tmp = i;
		for(int j = 2; j * j <= tmp; j++)
			while(tmp % j == 0)
				tmp /= j , val[i][num[j]]++;

		if(tmp > 1)
			val[i][num[tmp]]++;

		for(int j = 0; j < id; j++)
			val[i][j] += val[i - 1][j];
	}

	for(int i = 1; i < maxn; i++)
		reverse(val[i].begin() , val[i].end());

	for(int i = 1; i <= maxN; i++)
		shit[i] = i;

	int sz = maxN + 1;
	for(int i = 1; i + 1 <= maxN; i++)
	{
		int x = shit[i] , y = shit[i + 1];

		vector<int> tmp(id , 0);
		for(int j = 0; j < id; j++)
		{
			if(val[x][j] != val[y][j])
			{
				tmp[j] = min(val[x][j] , val[y][j]);
				break;
			}
			else
				tmp[j] = val[x][j];
		}

		val[sz] = tmp;
		shit[sz] = sz;
		sz++;
	}

	sort(shit + 1 , shit + sz , cmp);

	int pt = 1;
	for(int i = 1; i < sz; i++)
		if(val[shit[i]] != val[shit[i - 1]])
			shit[pt++] = shit[i];
	sz = pt;

	stack<int> st;
	for(int i = 1; i < sz; i++)
	{
		while(!st.empty() && !is_par(st.top() , shit[i]))
			st.pop();

		if(!st.empty())
			adj[st.top()].pb(i);
		st.push(i);
	}

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if(x == 0)
			x = 1;
		t[x]++;
	}

	dfs(1);
	int root = getCent(1);

	ll res = 0;
	for(int i = 1; i <= maxN; i++)
	{
		int tmp = 0;
		for(int j = 0; j < id; j++)
		{
			tmp = j;
			if(val[root][j] != val[i][j])
				break;
		}

		if(val[root][tmp] == val[i][tmp])
			continue;

		ll x = 0;
		for(int j = tmp + 1; j < id; j++)
			x += val[root][j] + val[i][j];
		x += max(val[root][tmp] , val[i][tmp]) - min(val[root][tmp] , val[i][tmp]);

		res += x * t[i];
	}

	cout << res << endl;
}