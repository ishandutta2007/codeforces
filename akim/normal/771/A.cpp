#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

int n,m;
vi g[N];
bool used[N];
int mm,nn;

map <pair<int,int> ,int> ma;
void dfs(int v, int p = -1){
    used[v] = 1;
    nn++;
    for(int i = 0; i < g[v].size(); i++)
    {
     	int to = g[v][i];
     	if(!ma.count(mp(to,v))){
     		mm++;
     		ma[mp(to,v)] = 1;
     		ma[mp(v,to)] = 1;
     	}
     	if(!used[to]){
     		dfs(to,v);
     	}
    }
}

int main () {
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v; i <= m; i++){
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			nn = 0;
			mm = 0;
			dfs(i);
			if(nn == 1) continue;
			if(mm != 1ll * nn * (nn - 1) / 2){
				puts("NO");
				exit(0);
			}
		}
	}
	puts("YES");


return 0;
}