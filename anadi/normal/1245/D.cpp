#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int rep[N];
int x[N], y[N], c[N];
vector <pair <LL, PII> > Edges;

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	a = Find(a), b = Find(b);
	if(a == b)	return false;
	rep[a] = b;
	return true;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &x[i], &y[i]);
	
	for(int i = 1; i <= n; ++i){
		int t;
		scanf("%d", &t);
		
		rep[i] = i;
		Edges.push_back({t, {0, i}});
	}

	for(int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			Edges.push_back({1LL * (c[i] + c[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), {i, j}});
	
	long long sum = 0;
	sort(Edges.begin(), Edges.end());
	
	vector <int> stat;
	vector <PII> ans;
	
	for(auto v: Edges)
		if(Union(v.nd.st, v.nd.nd)){
			if(v.nd.st == 0)
				stat.push_back(v.nd.nd);
			else
				ans.push_back(v.nd);
			sum += v.st;
		}
	
	printf("%lld\n", sum);
	printf("%d\n", (int)stat.size());
	for(auto v: stat)
		printf("%d ", v);
	puts("");

	printf("%d\n", (int)ans.size());
	for(auto v: ans)
		printf("%d %d\n", v.st, v.nd);
	puts("");
	return 0;
}