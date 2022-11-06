#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int from[maxn] , to[maxn] , w[maxn] , pos[maxn] , topol;
bool visited[maxn];

vector<int> out[maxn];

void dfs(int v , int x)
{
	visited[v] = 1;
	for(auto e : out[v])
		if(w[e] > x && !visited[to[e]])
			dfs(to[e] , x);

	pos[v] = topol++;
}

bool check(int n , int m , int x)
{
	topol = 0;

	memset(visited , 0 , sizeof visited);
	memset(pos , -1 , sizeof pos);
	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i , x);

	for(int i = 0; i < m; i++)
		if(w[i] > x && pos[from[i]] < pos[to[i]])
			return 0;

	return 1;
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
		cin >> a >> b >> w[i];
		a-- , b--;

		out[a].pb(i);
		from[i] = a , to[i] = b;
	}

	int L = -1 , R = 1e9 + 10;
	if(!check(n , m , R))
		cout << 1/0;

	while(R - L > 1)
	{
		int M = (L + R) / 2;
		if(check(n , m , M))
			R = M;
		else
			L = M;
	}

	check(n , m , R);

	vector<int> ans;
	for(int i = 0; i < m; i++)
		if(w[i] <= R && pos[from[i]] < pos[to[i]])
			ans.pb(i);

	cout << R << " " << ans.size() << endl;
	for(auto x : ans)
		cout << x + 1 << " ";
	cout << endl;
}