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

int n, k;
int d[N];
int cnt[N];
queue <int> Q;
vector <int> G[N];

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);

		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i)
		if(G[i].size() == 1)
			Q.push(i);
		else
			d[i] = -1;
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();

		for(int v: G[u]){
			if(d[v] == -1){
				d[v] = d[u] + 1;
				Q.push(v);
			}
			
			if(d[v] == d[u] + 1)
				cnt[v]++;
		}
	}
	
	int cntk = 0;
	for(int i = 1; i <= n; ++i){
		if(d[i] == k)
			++cntk;

		if(d[i] > k){
			puts("No");
			return 0;
		}
		
		if(d[i] != 0 && cnt[i] < 3){
			puts("No");
			return 0;
		}
		
		for(int v: G[i])
			if(d[v] == d[i]){
				puts("No");
				return 0;
			}
	}
	
	if(cntk == 1)
		puts("Yes");
	else
		puts("No");
	return 0;
}