#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;
const int maxs = 11;
const int maxd = 50 + 20;
const int mod = 1e9 + 7;

int nxt[maxn * maxd][maxs] , f[maxn * maxd] , id = 1;
bool fn[maxn * maxd];

int dp[maxn * maxd][maxd][2];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

void addTrie(string s)
{
	int pos = 0;
	for(int ch : s)
	{
		if(!nxt[pos][ch - '0'])
			nxt[pos][ch - '0'] = id++;
		pos = nxt[pos][ch - '0'];
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

int solve(string r , int val = 1)
{
	int d = r.size() , pos = 0 , res = 0 , is = 0;
	for(int i = 0; i < d; i++)
	{
		for(int j = !i; j < r[i] - '0'; j++)
		{
			int tpos = nxt[pos][j];
			mkay(res += dp[tpos][d - i - 1][is | fn[tpos]]);
		}
		pos = nxt[pos][r[i] - '0'];
		is |= fn[pos];
	}

	mkay(res += dp[pos][0][is] * val);

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s , x , y;
	cin >> s >> x >> y;

	int tmp = s.size() , d = x.size();
	for(int i = 0; i + d / 2 <= tmp; i++)
		addTrie(s.substr(i , d / 2));
	aho();

	for(int i = 0; i < id; i++)
		dp[i][0][1] = 1;

	for(int j = 1; j <= d; j++)
		for(int i = 0; i < id; i++)
			for(int k = fn[i]; k < 2; k++)
				for(int x = 0; x < 10; x++)
				{
					int u = nxt[i][x];
					mkay(dp[i][j][k] += dp[u][j - 1][k | fn[u]]);
				}

	int ans;
	mkay(ans = solve(y) - solve(x , 0));

	cout << ans << endl;
}