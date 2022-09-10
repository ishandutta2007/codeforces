#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int d[N];
bool type[N];
queue <int> Q[2];
vector <int> G[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &type[i]);
	
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		d[v]++;
	}
	
	for(int i = 0; i < n; ++i)
		if(d[i] == 0)
			Q[type[i]].push(i);
	
	int res = 0;
	while(Q[0].size() || Q[1].size()){
		while(!Q[0].empty()){
			int u = Q[0].front();
			Q[0].pop();
			
			for(int v: G[u]){
				d[v]--;
				if(d[v] == 0)
					Q[type[v]].push(v);
			}
		}
		
		res += Q[1].size() > 0;
		while(!Q[1].empty()){
			int u = Q[1].front();
			Q[1].pop();
			
			for(int v: G[u]){
				d[v]--;
				if(d[v] == 0)
					Q[type[v]].push(v);
			}
		}
	}
	
	printf("%d\n", res);
	return 0;
}