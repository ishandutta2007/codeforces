#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
struct edge{
	int v, u, l, r;
};


int n, q, k, sz[N], p[N], a[N], b[N], c[N], type[N], ded[N];
vector< pii > his;
int pp(int v){
	if(p[v] == v)
		return v;
	return pp(p[v]);
}
void unite(int v, int u){
	v = pp(v);
	u = pp(u);
	if(v == u){
		his.pb({-1, -1});
	}else{
		if(sz[v] < sz[u])
			swap(v, u);	
		sz[v] += sz[u];
		p[u] = v;
		his.pb({v, u});
	}
}
void un_unite(){
	auto it = his.back();
	his.pop_back();
	if(it.f == -1)
		return;
	sz[it.f] -= sz[it.s];
	p[it.s] = it.s;
}   
void solve(int l, int r, vector< edge > e){
	vector < edge > ee;
	int cnt = 0;	
	for(auto it : e){
		if(it.v == it.u)
			continue;
		if(it.l <= l && r <= it.r){
			cnt++;
			unite(it.v, it.u);
			continue;
		}
		if(it.r < l || r < it.l)
			continue; 
		ee.pb(it);
	}
	if(l == r){
		if(type[l] == 2)
			printf("%d\n", sz[pp(a[l])]); 
	}else{
		int m = (l + r) >> 1;
		solve(l, m, ee);		
		solve(m + 1, r, ee);
	}
	while(cnt--)
		un_unite();
}
int main()
{
	scanf("%d%d%d", &n, &q, &k);
	for(int i = 0; i < N; i++)
		p[i] = i, sz[i] = 1, ded[i] = q;
	int cur_day = 0;
	for(int i = 1; i <= q; i++){
		scanf("%d", &type[i]);
		if(type[i] == 1)
			scanf("%d%d", &a[i], &b[i]);
		if(type[i] == 2)
			scanf("%d", &a[i]);
		c[i] = cur_day;
		if(type[i] == 3){
			ded[cur_day] = i;
			cur_day++;
		}
	}
	vector< edge > v;
	for(int i = 1; i <= q; i++)
		if(type[i] == 1)
			v.pb({a[i], b[i], i, ded[c[i] + k - 1]});						
	solve(1, q, v);
}