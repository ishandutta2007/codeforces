#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;
const int maxs = 10;

int x , nxt[maxn * maxs][maxs] , f[maxn * maxs];

bool fn[maxn * maxs];

int id = 1;

int dp[2][maxn * maxs];

void addTrie(vector<int> tmp)
{
	int pos = 0;
	for(auto ch : tmp)
	{
		if(!nxt[pos][ch])
			nxt[pos][ch] = id++;

		pos = nxt[pos][ch];
	}

	fn[pos] = 1;
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

void bt(vector<int> tmp , int sm)
{
	if(sm > x)
		return;
	if(sm == x)
	{
		addTrie(tmp);
		return;
	}

	for(int j = 1; j <= 9; j++)
	{
		int sum = j;

		if((!tmp.empty() || j != x) && x % sum == 0)
			continue;

		bool has = 0;
		for(int i = (int)tmp.size() - 1; i > 0; i--)
		{
			sum += tmp[i];
			if(x % sum == 0)
				has = 1;
		}

		if(!has)
		{
			tmp.pb(j);
			bt(tmp , sm + j);
			tmp.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;

	cin >> s >> x;
	int n = s.size();

	bt(vector<int>() , 0);
	aho();

	memset(dp , 63 , sizeof dp);

	dp[0][0] = 0;
	for(int i = 0; i < n; i++)
	{
		int t = i & 1;
		memset(dp[t ^ 1] , 63 , sizeof dp[t ^ 1]);
		for(int j = 0; j < id; j++)
		{
			int t = i&1;

			int ns = nxt[j][s[i] - '0'];
			if(!fn[ns])
				dp[t ^ 1][ns] = min(dp[t ^ 1][ns] , dp[t][j]);

			dp[t ^ 1][j] = min(dp[t ^ 1][j] , dp[t][j] + 1);
		}
	}

	int res = 1e9;
	for(int i = 0; i < id; i++)
		res = min(res , dp[n & 1][i]);

	cout << res << endl;
}