#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

vector<int> out[maxn] , in[maxn] , topol , sa[maxn] , sb[maxn] , ea[maxn] , eb[maxn];

int a[maxn] , pos[maxn] , l[maxn] , r[maxn];

int fl[maxn] , fr[maxn] , mnout[maxn] , mxin[maxn];

bool visited[maxn] , shit[maxn];

void dfs(int v)
{
	visited[v] = 1;

	for(auto u : out[v])
		if(!visited[u])
			dfs(u);

	topol.pb(v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		out[a].pb(b);
		in[b].pb(a);
	}

	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);

	reverse(topol.begin() , topol.end());
	for(int i = 0; i < n; i++)
		pos[topol[i]] = i;

	for(int i = 0; i < n; i++)
	{
		int v = topol[i];

		int mn = n;
		for(auto u : out[v])
			mn = min(mn , pos[u]);

		sa[i + 1].pb(v);
		ea[mn].pb(v);
		a[i + 1]++;
		a[mn]--;

		int mx = -1;
		for(auto u : in[v])
			mx = max(mx , pos[u]);

		sb[mx + 1].pb(v);
		eb[i].pb(v);
		a[mx + 1]++;
		a[i]--;

		fr[v] = n;
		fl[v] = -1;

		for(auto u : out[v])
			if(pos[u] > mn)
				fr[v] = min(fr[v] , pos[u]);

		for(auto u : in[v])
			if(pos[u] < mx)
				fl[v] = max(fl[v] , pos[u]);
	}

	for(int v = 0; v < n; v++)
	{
		mnout[v] = n , mxin[v] = -1;
		for(auto u : out[v])
			mnout[v] = min(mnout[v] , fl[u]);
		for(auto u : in[v])
			mxin[v] = max(mxin[v] , fr[u]);
	}

	for(int i = 1; i < n; i++)
		a[i] += a[i - 1];

	memset(visited , 0 , sizeof visited);

	vector<int> R;
	for(int i = 0; i < n; i++)
	{
		for(auto v : sa[i])
			visited[v] = 1 , R.pb(v);
		for(auto v : ea[i])
			visited[v] = 0;

		while(!R.empty() && !visited[R.back()])
			R.pop_back();
		if(!R.empty())
			l[topol[i]] = R.back();
		else
			l[topol[i]] = -1;
	}

	memset(visited , 0 , sizeof visited);
	R.clear();
	for(int i = 0; i < n; i++)
	{
		for(auto v : sb[i])
			visited[v] = 1 , R.pb(v);
		for(auto v : eb[i])
			visited[v] = 0;

		while(!R.empty() && !visited[R.back()])
			R.pop_back();
		if(!R.empty())
			r[topol[i]] = R.back();
		else
			r[topol[i]] = -1;
	}

	int ans = 0;
	for(int v = 0; v < n; v++)
	{
		if(a[pos[v]] > 1)
			continue;

		if(!a[pos[v]])
		{
			ans++;
			continue;
		}

		bool f = 1;
		if(l[v] >= 0)
		{
			int u = l[v];

			if(mxin[u] > pos[v])
				f = 0;
		}
		else
		{
			int u = r[v];

			if(mnout[u] < pos[v])
				f = 0;
		}

		ans += f;
	}

	cout << ans << endl;

}