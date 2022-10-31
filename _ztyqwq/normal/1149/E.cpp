#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
}e[200001];
int ecnt = 0, head[200001];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int sg[200001];
const int MEX_MAX = 650;
inline void dfs(int u)
{
	if(sg[u] >= 0)
		return;
	bool mex[MEX_MAX + 5] = {false};
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		dfs(v);
		mex[sg[v]] = true;
	}
	for(int i = 0; i <= MEX_MAX; i++)
		if(!mex[i])
		{
			sg[u] = i;
			break;
		}
}
int xorsum[MEX_MAX + 1];
int a[200001];
int main()
{
	memset(head, -1, sizeof(head));
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while(m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		addedge(u, v);
	}
	memset(sg, -1, sizeof(sg));
	for(int i = 1; i <= n; i++)
		if(sg[i] == -1)
			dfs(i);
	memset(xorsum, 0, sizeof(xorsum));
	for(int i = 1; i <= n; i++)
		xorsum[sg[i]] ^= a[i];
	int mx = -1;
	for(int i = MEX_MAX; i >= 0; i--)
		if(xorsum[i])
		{
			mx = i;
			break;
		}
	if(mx == -1)
	{
		printf("LOSE\n");
		return 0;
	}
	printf("WIN\n");
	int pos = -1;
	for(int i = 1; i <= n; i++)
		if(sg[i] == mx && ((a[i] ^ xorsum[mx]) < a[i]))
		{
			pos = i;
			break;
		}
	a[pos] ^= xorsum[mx];
	xorsum[mx] = 0;
	for(int i = head[pos]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(xorsum[sg[v]])
			a[v] ^= xorsum[sg[v]], xorsum[sg[v]] = 0;
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	putchar('\n');
	return 0;
}