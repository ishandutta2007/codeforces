#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, k;
int dist[2][N];

bool spec[N];
vector <int> G[N];

int order[N];
int order2[N];
pair <PII, int> mx[N];

bool cmp(int a, int b){
	return dist[1][a] < dist[1][b];
}

bool cmp2(int a, int b){
	return dist[0][a] < dist[0][b];
}

void bfs(int t, int s){
	for(int i = 1; i <= n; ++i)
		dist[t][i] = -1;
	dist[t][s] = 0;
	
	queue <int> Q;
	Q.push(s);
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(auto v: G[u])
			if(dist[t][v] == -1){
				dist[t][v] = dist[t][u] + 1;
				Q.push(v);
			}
	}
}

bool check(int min_d){
	int it = k + 1;
	for(int i = 1; i <= k; ++i){
		int u = order2[i];
		while(it > 1 && dist[1][order[it - 1]] + dist[0][u] >= min_d)
			--it;
		
		int d = mx[it].st.nd == u ? mx[it].nd : mx[it].st.st;
		if(it <= k && d + dist[1][u] >= min_d)
			return true;
	}
	
	return false;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= k; ++i){
		int x;
		scanf("%d", &x);
		spec[x] = true;
	}
	
	for(int i = 1; i <= m; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	bfs(0, 1);
	bfs(1, n);
	
	for(int i = 1; i <= n; ++i)
		if(spec[i])
			for(auto v: G[i])
				if(spec[v]){
					printf("%d\n", dist[0][n]);
					exit(0);
				}
	
	k = 0;
	for(int i = 1; i <= n; ++i)
		if(spec[i]){
			order[++k] = i;
			order2[k] = i;
		}

	sort(order + 1, order + k + 1, cmp);
	sort(order2 + 1, order2 + k + 1, cmp2);
	
	mx[k] = {{dist[0][order[k]], order[k]}, -N};
	for(int i = k - 1; i >= 1; --i){
		int cand = dist[0][order[i]];
		if(cand >= mx[i + 1].st.st)
			mx[i] = {{cand, order[i]}, mx[i + 1].st.st};
		else if(cand >= mx[i + 1].nd)
			mx[i] = {mx[i + 1].st, cand};
		else
			mx[i] = mx[i + 1];

//		printf("%d -> %d %d %d\n", i, mx[i].st.st, mx[i].st.nd, mx[i].nd);
	}
	
	int s = 0, e = n;
	while(s < e){
		int mid = (s + e + 1) / 2;
		if(check(mid))
			s = mid;
		else
			e = mid - 1;
	}
	
	printf("%d\n", min(s + 1, dist[0][n]));
	return 0;
}