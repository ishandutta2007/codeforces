#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 1000005
#define LOGN 21

int timer = 0;

int N;
std::vector<int> Adj[MAXN];
std::vector<int> lSeq[MAXN];
int level[MAXN];
std::vector<int> heads;
//int freei = 0;
int parent[MAXN][LOGN];
int btime[MAXN], etime[MAXN];
//int seg[4*LOGN*MAXN];
//int left[4*LOGN*MAXN];
//int right[4*LOGN*MAXN];
int roots[MAXN];

//int build(int l = 0, int r = N-1)
//{
//	int id = freei++;
//	if(l == r)
//	{
//		seg[id] = 0;
//		left[id] = right[id] = -1;
//	}
//	else
//	{	
//		seg[id] = -1;
//		int m = (l + r)/2;
//		left[id] = build(l, m);
//		right[id] = build(m+1, r);
//	}
//	return id;
//}
//
//int update(int x, int id, int l = 0, int r = N-1)
//{
//	int newId = freei++;
//	if(l == r)
//		seg[newId] = seg[id]+1;
//	else
//	{
//		int m = (l+r)/2;
//		left[newId] = left[id];
//		right[newId] = right[id];
//		
//		if(x <= m)
//			left[newId] = update(x, left[id], l, m);
//		else
//			right[newId] = update(x, right[id], m+1, r);
//	}
//	return newId;
//}
//
//int get(int x, int id, int l = 0, int r = N-1)
//{
//	if(l == r)
//		return seg[id];
//	else
//	{
//		int m = (l+r)/2;
//		if(x <= m)
//			return get(x, left[id], l, m);
//		else
//			return get(x, right[id], m+1, r);
//	}
//}

int anc(int u, int k)
{
	int ans = u;
	int i = LOGN;
	while(k > 0)
	{
		if((1 << i) <= k)
		{
			if(ans != -1)
				ans = parent[ans][i];
			k -= 1 << i;
		}
		i--;
	}
	
	return ans;
}

void dfs(int u, int p)
{
	btime[u] = ++timer;
	parent[u][0] = p;
	
	if(p == -1)
		level[timer] = 0;
	else
		level[timer] = level[btime[p]] + 1;
	
	lSeq[level[timer]].push_back(timer);
	
	for(int i = 1; i < LOGN; i++)
		parent[u][i] = (parent[u][i-1] >= 0) ? parent[parent[u][i-1]][i-1] : -1;
	
	for(int i = 0; i < Adj[u].size(); i++)
		dfs(Adj[u][i], u);
	
	etime[u] = timer;
}

int main()
{
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
	{
		int p;
		scanf("%d", &p);
		if(p)
			Adj[p-1].push_back(i);
		else
			heads.push_back(i);
	}
	
	for(int i = 0; i < heads.size(); i++)
		dfs(heads[i], -1);
	
	int Q;
	std::cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		int v, p; int answer;
		scanf("%d %d", &v, &p); v--;
		
		int a = anc(v, p);
		//std::cout << a << std::endl;
		if(a == -1)
			answer = 0;
		else
		{
			int l = std::lower_bound(lSeq[level[btime[v]]].begin(), lSeq[level[btime[v]]].end(), btime[a]) - lSeq[level[btime[v]]].begin();
			int r = std::upper_bound(lSeq[level[btime[v]]].begin(), lSeq[level[btime[v]]].end(), etime[a]) - lSeq[level[btime[v]]].begin();
			answer = r-l-1;
		}
		printf("%d\n", answer);
	}
	
	return 0;
}