#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 131072;
const int lgMAXN = 17;
const int MAXA = 10;
int N, M, Q;

vector<int> conn[MAXN];
int living[MAXN][lgMAXN+1][MAXA];
int livingsz[MAXN][lgMAXN+1];
int parent[MAXN][lgMAXN+1]; 
int height[MAXN];

void dfs(int a)
{
	if(parent[a][0] != -1) height[a] = height[parent[a][0]] + 1;
	for(int i=0; i<conn[a].size(); i++)
	{
		int v=conn[a][i];
		if( v == parent[a][0]) continue;
		parent[v][0] = a;
		dfs(v);
	}
	return;
}

void calcLCA()
{
	parent[0][0] = -1;
	height[0] = 0;
	dfs(0);
	for(int j=1; j<=lgMAXN; j++)
		for(int i=0; i<N; i++)
		{
			if(parent[i][j-1] != -1)
				parent[i][j] = parent[ parent[i][j-1] ] [j-1];
			else
				parent[i][j] = -1;
		}
}

void merge(const int _a[], const int asz, const int _b[], const int bsz, int *c, int& csz)
{
	int a[MAXA], b[MAXA];
	for(int i=0; i<min(MAXA, asz); i++) a[i]=_a[i];
	for(int i=0; i<min(MAXA, bsz); i++) b[i]=_b[i];
	csz = asz + bsz;
	int maxsz = min(MAXA, csz);
	int atp = 0;
	int btp = 0;
	for(int i=0; i<maxsz; i++)
	{
		if(atp==asz)
			c[i] = b[btp++];	
		else if(btp==bsz)
			c[i] = a[atp++];
		else
		{
			if(a[atp] < b[btp])
				c[i] = a[atp++];
			else
				c[i] = b[btp++];
		}
	}
	return;
}

void calcLiving()
{
	for(int j=1; j<=lgMAXN; j++)
	{
		for(int i=0; i<N; i++)
		{
			int p = parent[i][j-1];
			if(p != -1)
				merge(
					living[i][j-1], livingsz[i][j-1],
					living[p][j-1], livingsz[p][j-1],
					living[i][j], livingsz[i][j]
				);
			else
				merge(
					living[i][j-1], livingsz[i][j-1],
					NULL, 0,
					living[i][j], livingsz[i][j]
				);				
		}
	}
}

int calcans(int u, int v, int ans[])
{
	int ret = 0;
	if(height[u] < height[v]) u^=v^=u^=v;
	int desiredUp = height[u] - height[v];
	for(int i=0; i<=lgMAXN; i++)
	{
		int h = 1<<i;
		if(desiredUp & h)
		{
			int p = parent[u][i];
			merge(ans, ret, living[u][i], livingsz[u][i], ans, ret);
			u = p;
		}
	}
	if(u==v)
	{
		merge(ans, ret, living[u][0], livingsz[u][0], ans, ret);
		return ret;
	}
	int jump = lgMAXN;
	while(jump >= 0)
	{
		if(parent[u][jump] == parent[v][jump])
		{
			jump--;
			continue;
		}
		merge(ans, ret, living[u][jump], livingsz[u][jump],ans,ret);
		merge(ans, ret, living[v][jump], livingsz[v][jump],ans,ret);
		u=parent[u][jump];
		v=parent[v][jump];
	}
	//int p = parent[u][0];
	merge(ans, ret, living[u][1], livingsz[u][1], ans, ret);
	merge(ans, ret, living[v][0], livingsz[v][0], ans, ret);
	return ret;
}


int livingcnt[MAXN];
int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	for(int i=0; i<N-1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	for(int i=0; i<M; i++)
	{
		int city;
		scanf("%d", &city);
		city--;
		if(livingsz[city][0] < MAXA) living[city][0][livingsz[city][0]] = i+1;
		livingsz[city][0]++; 
	}
	calcLCA();
	calcLiving();
	for(int i=0; i<Q; i++)
	{
		int v, u, a;
		scanf("%d%d%d",&v, &u, &a);
		v--; u--;
		int ans[10];
		int ret = calcans(u, v, ans);
		printf("%d ", min(ret, a));
		for(int i=0; i< min(ret, a); i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}