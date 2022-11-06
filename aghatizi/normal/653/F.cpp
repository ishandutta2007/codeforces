#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int maxn = 5e5 + 20;

int gp , n , sa[maxn] , lcp[maxn] , tmp[maxn] , pos[maxn] , sum[maxn] , rx[maxn];
int par[maxn * 2] , h[maxn * 2] , ver[maxn * 2];
vector<int> adj[maxn * 2] , P[maxn * 2];

ll res;

bool cmp(int i , int j)
{
	if(pos[i] != pos[j])
		return pos[i] < pos[j];

	i += gp;
	j += gp;
	return (i < n && j < n) ? pos[i] < pos[j] : i > j;
}

void dfs(int v)
{
	for(auto u : adj[v])
	{
		int st = ver[u] , l = st + h[v] + 1 , r = st + h[u];
		if(rx[st] > r)
			dfs(u);

		r = min(rx[st] - 1 , r);

		int tmp = 0;
		tmp += upper_bound(P[sum[st]].begin() , P[sum[st]].end() , r) - P[sum[st]].begin();
		tmp -= lower_bound(P[sum[st]].begin() , P[sum[st]].end() , l) - P[sum[st]].begin();
		res += tmp;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> n >> s;

	for(int i = 0; i < n; i++)
		sa[i] = i , pos[i] = s[i];
	for(gp = 1; ; gp *= 2)
	{
		sort(sa , sa + n , cmp);
		for(int i = 0; i + 1 < n; i++)
			tmp[i + 1] = tmp[i] + cmp(sa[i] , sa[i + 1]);
		for(int i = 0; i < n; i++)
			pos[sa[i]] = tmp[i];
		if(tmp[n - 1] == n - 1)
			break;
	}

	for(int i = 0 , k = 0; i < n; i++)
		if(pos[i] != n - 1)
		{
			while(s[sa[pos[i] + 1] + k] == s[i + k])
				k++;
			lcp[pos[i]] = k;
			k -= (k != 0);
		}

	memset(ver , -1 , sizeof ver);
	int cnt = 1 , now = 1;
	par[cnt] = 0 , h[cnt] = n - sa[0] , ver[cnt] = sa[0] , cnt++;
	for(int i = 1; i < n; i++)
	{
		while(h[par[now]] > lcp[i - 1])
			now = par[now];
		if(h[now] != lcp[i - 1] && h[par[now]] != lcp[i - 1])
		{
			par[cnt] = par[now];
			h[cnt] = lcp[i - 1] , par[now] = cnt;
			cnt++;
		}
		if(h[now] != lcp[i - 1])
			now = par[now];
		par[cnt] = now , h[cnt] = n - sa[i] , now = cnt , ver[cnt] = sa[i] , cnt++;
	}

	for(int i = 1; i < cnt; i++)
		adj[par[i]].pb(i);
	for(int i = cnt - 1; i >= 0; i--)
		ver[par[i]] = ver[i];

	sum[0] = n;
	for(int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + ((s[i] == '(')? 1 : -1);

	for(int i = 0; i <= n; i++)
		P[sum[i]].pb(i);

	stack<int> st;
	for(int i = n; i >= 0; i--)
	{
		while(!st.empty() && sum[st.top()] >= sum[i])
			st.pop();
		if(st.empty())
			rx[i] = n + 1;
		else
			rx[i] = st.top();
		st.push(i);
	}

	dfs(0);
	cout << res << endl;
}