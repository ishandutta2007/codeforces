#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn = 3e5 + 100;
int n, m;
int p[maxn];
vector<int> g[maxn];
int u1[maxn];
int u2[maxn];

int T;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	int x = p[n];
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		if(v == x) u1[u] = true;
	}
	for(int i = n-1; i > 0; i--) {
		//if(!u1[i])continue;
		T++;
		for(int j = 0; j < g[p[i]].size(); j++) {
			u2[g[p[i]][j]] = T;
		}
		int j = i;
		while(j < n && u2[p[j+1]] == T) {
			swap(p[j], p[j+1]);
			j++;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(p[i] == x) {
			cout << n - i << "\n";
			return 0;
		}
	}

}