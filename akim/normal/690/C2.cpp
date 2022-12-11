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
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;
int n,m;
int a,b;
vi g[N];
bool  used[N];
int p,len;

void dfs(int v,int s){
	used[v] = 1;
	if(s > len){
		len = s;
		p = v;
	}
	for(int i = 0;i < g[v].size();i++){
		if(!used[g[v][i]]) dfs(g[v][i],s + 1);
	}
}

int main () {
	cin >> n >> m;
	for(int i = 1; i <= m;i++){
	 	cin >> a >> b;
	 	g[a].pb(b);
	 	g[b].pb(a);
	}
	if(m != n - 1){
		cout << "no";
		return 0;
	}
	dfs(1,0);
	len = 0;
	memset(used,0,sizeof(used));
	dfs(p,0);
	cout << len;

return 0;
}