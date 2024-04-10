#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define piz pair<int, pair<int,int> >
typedef long long ll;
const int P = 1e9+7;

const int maxn = 300050;

int n, m, t;
vector<int> adj[maxn];
queue<int> Q;
int col[maxn];

int main()
{
	#ifdef MPS
		freopen("1.in","r",stdin);
		freopen("1.out","w",stdout);
	#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; ++ i) adj[i].clear(), col[i] = -1;
		for (int i = 1; i <= m; ++ i)
		{
			int u, v; scanf("%d%d",&u,&v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		Q.push(1);
		while(!Q.empty())
		{
			int h = Q.front(), tag = 0;
			Q.pop();
			for (auto p : adj[h])
				if (col[p] == -1)
				{
					Q.push(p);
					col[p] = 0;
				}else if (col[p] == 1) tag = 1;
			if (tag == 1) col[h] = 0;
			else col[h] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++ i)
			if (col[i] == -1)
			{
				printf("NO\n");
				goto GG;
			}
		printf("YES\n");
		for (int i = 1; i <= n; ++ i) cnt += col[i];
		printf("%d\n",cnt);
		for (int i = 1; i <= n; ++ i) if (col[i]) printf("%d ", i);
		printf("\n");
		GG:;
	}
	return 0;
}