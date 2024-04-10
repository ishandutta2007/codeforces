#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n;
int deg[111];
int a[111];
pii b[111];
vector<int> g[111];
int nv[111];
double ans[111];
void dfs(int v, int p, double sd){
	sd+=1;
	double c = 2.0/deg[v];
	int j = 0;
	for(int i = 0; i < g[v].size(); i++){
		int ind = g[v][i];
		int to = b[ind].f ^ b[ind].s ^ v;
		if(to == p){
			j = i;
		}
	}
	int x = 1; 
	for(int i = (j + 1) % g[v].size(); i != j; i = (i + 1) % g[v].size()){
		int ind = g[v][i];
		ans[ind] = sd + c * x;
		nv[ind] = v;
		dfs(b[ind].f ^ b[ind].s ^ v, v, sd + c * x);
		x++;
	}
}
void solve(){
	cin>>n;
	for(int i = 1, x, y; i < n; i++){
		cin >> x >> y;
		g[x].pb(i);
		g[y].pb(i);
		b[i]=mp(x, y);
		deg[x]++;
		deg[y]++;
	}
	double c = 2.0/deg[1];
	for(int i = 0; i < g[1].size(); i++){
		int ind = g[1][i];
		int to = b[ind].s ^ b[ind].f ^ 1;
		ans[ind] = c * i;
		dfs(to, 1, c*i);
		nv[ind] = 1;
	}
	printf("%d\n", n-1);
	for(int i = 1; i < n;i++ ){
		while(ans[i] >= 2) ans[i] -= 2;
		if(ans[i] <= 1){
			printf("%d %d %d %d %.12lf\n", 1, i, nv[i], b[i].f ^ b[i].s ^ nv[i], ans[i]);
		}else {
			printf("%d %d %d %d %.12lf\n", 1, i, b[i].f ^ b[i].s ^ nv[i], nv[i], ans[i] - 1);	
		}
	}
}

int main () {
    //cout << "Hello world\n";
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}