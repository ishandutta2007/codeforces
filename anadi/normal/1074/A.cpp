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
const LL INF = 1e18 + 9LL;

int n, m;
int sub[N];
vector <int> block;
int rep[N], mn[N], mx[N];
vector <pair <int, PII> > V;

int Find(int a){
	return rep[a] == a ? a : rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	a = Find(a), b = Find(b);
	mn[a] = min(mn[a], mn[b]);
	mx[a] = max(mx[a], mx[b]);
	rep[b] = a;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		block.push_back(a);
	}
	
	for(int i = 1; i <= m; ++i){
		rep[i] = i;
		int x1, x2, y;
		scanf("%d %d %d", &x1, &x2, &y);
		V.push_back({y, {x1, x2}});
	}
	
	sort(V.begin(), V.end());
	for(int i = 0; i < V.size(); ++i){
		mn[i + 1] = V[i].nd.st;
		mx[i + 1] = V[i].nd.nd;

		if(i == 0 || V[i].st != V[i - 1].st)
			continue;
		
		int id = Find(i);
		if(mx[id] >= mn[i + 1] - 1)
			Union(id, i + 1);
	}
	
	block.push_back(0);
	block.push_back(1e9);
	block.push_back(1e9 + 1);
	sort(block.begin(), block.end());
	
	int res = MX, start = 0;
	for(int i = 1; i <= m; ++i)
		if(rep[i] == i && mn[i] == 1){
			++start;
			sub[upper_bound(block.begin(), block.end(), mx[i]) - block.begin()]++;
		}
	
	for(int i = 0; i <= n; ++i){
		start -= sub[i + 1];
		res = min(res, i + start);
	}

	printf("%d\n", res);
	return 0;
}