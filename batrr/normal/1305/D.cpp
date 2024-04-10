#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
vector< int > g[N];
int n, R;
bool was[N];
int ask(int a, int b){
	if(a == b)
		return a;
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int c;
	scanf("%d", &c);
	return c;
}
int ans(int v){
	printf("! %d\n", v);
	fflush(stdout);
	exit(0);
}
void solve(int v){
	was[v] = 1;
	vector< int > cond;
	for(auto to : g[v])
		if(!was[to])
			cond.pb(to);
	for(int i = 0; i + 1 < cond.size(); i += 2){
		int a = cond[i];
		int b = cond[i + 1];
		int c = ask(a, b);
		if(c == v)
			continue;
		R = c;
		solve(c);
	}
	if(cond.size() & 1){
		solve(cond.back());
	}else{
		ans(ask(R, v));
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	R = 1;
	solve(1);
}