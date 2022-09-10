#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e5 + 7;

int n, m;
int ans[N];
set <PII> S;

int main(){
	scanf("%d %d", &n, &m);
	if(2 * m == 1LL * n * (n - 1)){
		puts("NO");
		return 0;
	}
	
	for(int i = 1; i <= m; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		
		if(x > y)	swap(x, y);
		S.insert({x, y});
	}
	
	int from = -1, to = -1;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(S.find({i, j}) == S.end()){
				from = i, to = j;
				break;
			}
	
	if(from == -1){
		puts("NO");
		return 0;
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(i != from && i != to)
			ans[i] = ++cnt;
	
	ans[from] = n - 1;
	ans[to] = n;
	
	puts("YES");
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
	
	ans[from] = n;
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}