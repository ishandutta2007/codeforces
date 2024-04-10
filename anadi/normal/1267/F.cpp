#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n, m, ka, kb;
int cnt[N];
vector <int> fa, fb;

void solve(){
	scanf("%d %d %d %d", &n, &m, &ka, &kb);
	fa.resize(ka); fb.resize(kb);
	
	if(ka >= m || kb >= n){
		puts("No");
		exit(0);
	}

	for(int i = 0; i < ka; ++i)
		scanf("%d", &fa[i]);
	for(int i = 0; i < kb; ++i)
		scanf("%d", &fb[i]);
	
	while((int)fa.size() < m - 1)
		fa.push_back(1);
	while((int)fb.size() < n - 1)
		fb.push_back(n + m);

	for(auto v: fa)
		cnt[v]++;
	for(auto v: fb)
		cnt[v]++;
	
	set <int> S;
	for(int i = 1; i <= n + m; ++i)
		if(cnt[i] == 0)
			S.insert(i);
	
	puts("Yes");
	ka = 0, kb = 0;

	for(int i = 0; i < n + m - 2; ++i){
		if(*S.begin() <= n){
			assert(kb < n);
			printf("%d %d\n", *S.begin(), fb[kb]);
			S.erase(S.begin());
			
			cnt[fb[kb]]--;
			if(cnt[fb[kb]] == 0)
				S.insert(fb[kb]);
			++kb;
		}
		else{
			assert(ka < m);
			printf("%d %d\n", *S.begin(), fa[ka]);
			S.erase(S.begin());
			
			cnt[fa[ka]]--;
			if(cnt[fa[ka]] == 0)
				S.insert(fa[ka]);
			++ka;
		}
	}
	
	printf("%d %d\n", *S.begin(), *S.rbegin());
}

int main(){
	int cases = 1;
	while(cases--)
		solve();
	return 0;
}