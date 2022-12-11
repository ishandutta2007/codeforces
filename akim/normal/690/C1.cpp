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

void dfs(int v){
	used[v] = 1;
	for(int i = 0;i < g[v].size();i++){
		if(!used[g[v][i]]) dfs(g[v][i]);
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
	dfs(1);
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			puts("no");
			return 0;
		}
	}
	puts("yes");

return 0;
}