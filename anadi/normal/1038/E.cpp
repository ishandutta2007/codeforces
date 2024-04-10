#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int all = 0;

int add[4];
bool vis[4];
vector <int> edge[4][4];

void dfs(int u){
	vis[u] = true;
	for(int i = 0; i < 4; ++i)
		if(!vis[i] && edge[min(u, i)][max(u, i)].size() > 0)
			dfs(i);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int u, c, v;
		scanf("%d %d %d", &u, &c, &v);
	
		all += c;
		u--, v--;

		if(u > v) swap(u, v);
		edge[u][v].push_back(c);
	}
	
	for(int i = 0; i < 4; ++i)
		for(int j = i; j < 4; ++j){
			sort(edge[i][j].begin(), edge[i][j].end());
			reverse(edge[i][j].begin(), edge[i][j].end());
		}

	int res = 0;
	for(int i = 0; i < 4; ++i){
		int t = 0;
		for(int v: edge[i][i])
			t += v;

		add[i] = t;
		res = max(res, t);
	}
	
	for(int i = 0; i < 4; ++i)
		for(int j = i + 1; j < 4; ++j){
			int t = 0;
			for(int v: edge[i][j])
				t += v;
			
			if(t > 0)
				res = max(res, add[i] + add[j] + t);
		}
	
	for(int i = 0; i < 4; ++i){
		int s = all;
		for(int j = 0; j < 4; ++j)
			for(int v: edge[min(i, j)][max(i, j)])
				s -= v;
		
		bool ok = true;
		for(int j = 0; j < 4; ++j){
			if(i == j)
				continue;

			bool out = false;
			for(int k = 0; k < 4; ++k)
				if(k != j && k != i && edge[min(j, k)][max(j, k)].size() > 0)
					out = true;
			ok &= out;
		}
		
		if(ok)
			res = max(res, s);
	}
	
	for(int i = 0; i < 64; ++i){
		int bit = 0;
		vector <pair <PII, int> > del;

		bool bad = false;
		for(int j = 0; j < 4; ++j)
			for(int k = j + 1; k < 4; ++k){
				if(i & (1 << bit)){
					if(edge[j][k].size() == 0)
						bad = true;
					else if(edge[j][k].size()%2 == 0){
						del.push_back({{j, k}, edge[j][k].back()});
						edge[j][k].pop_back();
					}
				}
				else{
					if(edge[j][k].size()%2 == 1){
						del.push_back({{j, k}, edge[j][k].back()});
						edge[j][k].pop_back();
					}
				}

				++bit;
			}
		
		if(!bad){
			for(int j = 0; j < 4; ++j)
				vis[j] = false;			
			dfs(0);

			bool ok = true;
			for(int j = 0; j < 4; ++j)
				ok &= vis[j];
			
			if(ok){
				int np = 0;
				for(int j = 0; j < 4; ++j){
					int dg = 0;
					for(int k = 0; k < 4; ++k)
						if(j != k)
							dg += edge[min(j, k)][max(j, k)].size();
					
					np += dg%2;
				}
				
				if(np < 4){
					int s = all;
					for(auto v: del)
						s -= v.nd;
					res = max(res, s);
				}
			}
		}
		
		for(auto v: del)
			edge[v.st.st][v.st.nd].push_back(v.nd);
	}
	
	printf("%d\n", res);
	return 0;
}