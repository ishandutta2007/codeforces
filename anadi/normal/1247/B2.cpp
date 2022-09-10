#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n, k, d;
int in[N];

int all;
int cnt[N];

void add(int x){
	if(cnt[x] == 0)
		++all;
	cnt[x]++;
}

void rmv(int x){
	cnt[x]--;
	if(cnt[x] == 0)
		--all;
}

void solve(){
	scanf("%d %d %d", &n, &k, &d);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i <= d; ++i)
		add(in[i]);
	
	int ans = all;
	for(int i = d + 1; i <= n; ++i){
		add(in[i]);
		rmv(in[i - d]);
		ans = min(ans, all);
	}
	
	for(int i = 0; i < d; ++i)
		rmv(in[n - i]);
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}