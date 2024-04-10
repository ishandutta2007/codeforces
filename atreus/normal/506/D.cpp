#include <iostream>
#include <map>
#include <unordered_map>
#define F first
#define S second
using namespace std;
const int maxn = 1e5 + 9;
unordered_map <int, int> par[maxn], mp[maxn];
int n, m;

int get (int u, int col){
	return par[u][col] > 0? par[u][col] = get (par[u][col], col) : u;
}

void merge (int u, int w, int col){
	if ((u = get (u, col)) == (w = get (w, col)))
		return;
	int x = par[u][col] , y = par[w][col];
	if (x > y)
		swap(u, w),swap(x,y);

	par[u][col] += y - 1;
	par[w][col] = u;
}

int main (){
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++){
		int u, w, col;
		scanf ("%d %d %d", &u, &w, &col);
		merge (u, w, col);
	}
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; i++){
		int u, w;
		scanf ("%d %d", &u, &w);
		if (!mp[min(u,w)].count(max(w,u))){
			int cnt = 0;
			if (par[u].size() > par[w].size())
				swap (u, w);
			for (auto p : par[u]){
				if (par[w].count(p.F) && get (u, p.F) == get (w, p.F))
					cnt ++;
			}
			mp[min(w,u)][max(w,u)] = cnt;
		}
		printf ("%d\n", mp[min(u,w)][max(u,w)]);
	}
}